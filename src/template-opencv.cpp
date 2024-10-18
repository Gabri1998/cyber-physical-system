#include "cluon-complete.hpp"
#include "opendlv-standard-message-set.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "VisionBasedNavigation.hpp"
#include "ControlCommands.hpp"
#include "DataLogger.hpp"
#include "fileio.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <atomic>
#include <signal.h>
#include <sstream>
#include <ctime>
#include <mutex>
#include <fstream>
#include <filesystem>

std::atomic<bool> should_exit{false};
static bool isConeColorDetermined{false};
bool *isBlueLeft = new bool(false);

float gsrBefore = 0;

int imgNum = 0;

// Signal handler function
void signalHandler(int signum) {
    (void)signum;
    should_exit = true;
}

int main(int argc, char **argv) {
    float left_voltage_data;
    float right_voltage_data;
    int retCode{1};
    auto commandlineArguments = cluon::getCommandlineArguments(argc, argv);

    if ((0 == commandlineArguments.count("name")) ||
        (0 == commandlineArguments.count("width")) ||
        (0 == commandlineArguments.count("height")) ||
        (0 == commandlineArguments.count("cid"))) {
        std::cerr << argv[0] << " attaches to a shared memory area containing an ARGB image and transform it to HSV color space for inspection." << std::endl;
        std::cerr << "Usage: " << argv[0] << " --name=<name of shared memory area> --width=<W> --height=<H> --cid=<C>" << std::endl;
        std::cerr << " --name: name of the shared memory area to attach" << std::endl;
        std::cerr << " --width: width of the frame" << std::endl;
        std::cerr << " --height: height of the frame" << std::endl;
        std::cerr << " --cid: given cid" << std::endl;
        std::cerr << "Example: " << argv[0] << " --name=img.argb --width=640 --height=480 --cid=253" << std::endl;
    } else {
        const std::string NAME{commandlineArguments["name"]};
        const uint32_t WIDTH{static_cast<uint32_t>(std::stoi(commandlineArguments["width"]))};
        const uint32_t HEIGHT{static_cast<uint32_t>(std::stoi(commandlineArguments["height"]))};
        const uint16_t CID{static_cast<uint16_t>(std::stoi(commandlineArguments["cid"]))};

        signal(SIGINT, signalHandler);
        std::unique_ptr<cluon::SharedMemory> sharedMemory{new cluon::SharedMemory{NAME}};

        while (!sharedMemory->valid() && !should_exit) {
            sharedMemory = std::make_unique<cluon::SharedMemory>(NAME);
            std::cout << "Waiting for shared memory region to be created..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        if (sharedMemory && sharedMemory->valid()) {
            std::clog << argv[0] << ": Attached to shared memory '" << sharedMemory->name() << " (" << sharedMemory->size() << " bytes)." << std::endl;

            cluon::OD4Session od4{CID};

            // Receives steering angle information
            opendlv::proxy::GroundSteeringRequest gsr;
            std::mutex gsrMutex;
            auto onGroundSteeringRequest = [&gsr, &gsrMutex](cluon::data::Envelope &&env) {
                std::lock_guard<std::mutex> lck(gsrMutex);
                gsr = cluon::extractMessage<opendlv::proxy::GroundSteeringRequest>(std::move(env));
            };

            od4.dataTrigger(opendlv::proxy::GroundSteeringRequest::ID(), onGroundSteeringRequest);

            // Receives left right voltage information
            opendlv::proxy::VoltageReading leftVoltage;
            opendlv::proxy::VoltageReading rightVoltage;
            std::mutex voltageMutex;

            auto VoltageReading = [&](cluon::data::Envelope &&envelope) {
                std::lock_guard<std::mutex> lck(voltageMutex);
                if (envelope.senderStamp() == 1) {
                    leftVoltage = cluon::extractMessage<opendlv::proxy::VoltageReading>(std::move(envelope));
                    left_voltage_data = leftVoltage.voltage();
                } else if (envelope.senderStamp() == 3) {
                    rightVoltage = cluon::extractMessage<opendlv::proxy::VoltageReading>(std::move(envelope));
                    right_voltage_data = rightVoltage.voltage();
                }
            };

            od4.dataTrigger(opendlv::proxy::VoltageReading::ID(), VoltageReading);

            // Receives the distance data
	        opendlv::proxy::DistanceReading distanceReading;
	        std::mutex distanceMutex;
	        auto onDistanceReadingReceived = [&distanceReading, &distanceMutex](cluon::data::Envelope &&env) {
    		    std::lock_guard<std::mutex> lck(distanceMutex);
    		    distanceReading = cluon::extractMessage<opendlv::proxy::DistanceReading>(std::move(env));
	        };

	        od4.dataTrigger(opendlv::proxy::DistanceReading::ID(), onDistanceReadingReceived);

            VisionBasedNavigation vbn;
            ControlCommands cc;
            DataLogger dl("./res.csv");

            while (od4.isRunning() && cv::waitKey(10)) {
                cv::Mat img;
                sharedMemory->wait();

                sharedMemory->lock();
                {
                    cv::Mat wrapped(HEIGHT, WIDTH, CV_8UC4, sharedMemory->data());
                    img = wrapped.clone();
                }
                int64_t sampleTimeStamp = cluon::time::toMicroseconds(sharedMemory->getTimeStamp().second);
                sharedMemory->unlock();
                std::stringstream final;

                cv::Mat imgHSV;
                cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);
                cv::Mat imgSpaceBlue;
                cv::inRange(imgHSV, cv::Scalar(101, 110, 37), cv::Scalar(142, 255, 255), imgSpaceBlue);
                cv::Mat imgSpaceYellow;
                cv::inRange(imgHSV, cv::Scalar(13, 58, 133), cv::Scalar(26, 255, 255), imgSpaceYellow);
                cv::rectangle(img, cv::Point(170, 250), cv::Point(460, 400), cv::Scalar(0, 0, 255));
                cv::rectangle(img, cv::Point(200, 250), cv::Point(500, 400), cv::Scalar(0, 255, 0));

                cv::Rect centerLeft(170, 250, 270, 150);
                cv::Rect centerRight(170, 250, 320, 150);

                if (!isConeColorDetermined) {
                    isConeColorDetermined = vbn.analyzeMarkerColors(imgSpaceBlue, imgSpaceYellow, centerLeft, centerRight, *isBlueLeft);
                }

                cv::Mat imgLeft;
                cv::Mat imgRight;
                if (*isBlueLeft) {
                    imgLeft = imgSpaceBlue(centerLeft);
                    imgRight = imgSpaceYellow(centerRight);
                } else {
                    imgLeft = imgSpaceYellow(centerLeft);
                    imgRight = imgSpaceBlue(centerRight);
                }

                // Calculate the size of the cones
                int leftConePixels = cv::countNonZero(imgLeft);
                int rightConePixels = cv::countNonZero(imgRight);

                // Declare the variables to store steering value and distance value
                float groundSteering;
                float distance;

                // Add information of steering angle to both left and right images (Development Purpose)
                {
                    std::lock_guard<std::mutex> lck(gsrMutex);

                    groundSteering = gsr.groundSteering();

                    std::stringstream steeringText;
                    steeringText << "Ground Steering: " << groundSteering << " degrees";
                }

                // Display the distance data
		        {   
		            std::lock_guard<std::mutex> lck(distanceMutex);
		
		            // Sace distance data into a variable
		            distance = distanceReading.distance();
		        }

                // Extracts each frames as a jpg image (Development Purpose)
                std::string frameNum = std::to_string(imgNum++);
                std::string leftFilename = sharedMemory->name() + "_" + frameNum + "_left.jpg";
                std::string rightFilename = sharedMemory->name() + "_" + frameNum + "_right.jpg";

                if (commandlineArguments.count("verbose") && std::getenv("DISPLAY") != nullptr) {
                    try {
                        cv::imshow("Image", img);
                        cv::imshow("Left Steering Area", imgLeft);
                        cv::imshow("Right Steering Area", imgRight);

                        cv::waitKey(1);
                        
                    } catch (cv::Exception &e) {}
                }

                //isConeColorDetermined = vbn.analyzeMarkerColors(imgSpaceBlue, imgSpaceYellow, centerLeft, centerRight, *isBlueLeft);
                {
                    std::lock_guard<std::mutex> lck(gsrMutex);
                    float g1 = gsr.groundSteering();
                    float g2 = vbn.computeSteeringAngle(imgLeft, imgRight, left_voltage_data, right_voltage_data, isBlueLeft, distance, gsrBefore);

                    gsrBefore = g2;

                    if (commandlineArguments.count("stats")) {
                        cc.assessSteeringError(g1, g2);
                    }

                    if (commandlineArguments.count("cv-data"))
                    {
                        std::stringstream file_data;
                        // Append formatted data to the string stream "data"
                        file_data << g1 << "," << final.str();
                        // Write the commit values to the CSV file
                        write_file(std::to_string(g2), file_data.str());
                    }


                    final << sampleTimeStamp;

                    // Print it on a terminal so that I can convert it to csv
                    std::cout << "group_17;" << final.str() << ";" << g2 << std::endl;
                }
            }
        }
        retCode = 0;
    }
    return retCode;
}
