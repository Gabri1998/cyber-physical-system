#include "VisionBasedNavigation.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>

int cnt = 0;

VisionBasedNavigation::VisionBasedNavigation(float colorThreshold, float voltageThreshold)
   : colorThreshold(colorThreshold), voltageThreshold(voltageThreshold) {}

bool VisionBasedNavigation::analyzeMarkerColors(const cv::Mat& blueChannelImage, const cv::Mat& yellowChannelImage, const cv::Rect& leftRect, const cv::Rect& rightRect, bool& isLeftBlue) {
    if (blueChannelImage.empty() || yellowChannelImage.empty()) {
        std::cerr << "Invalid input data provided to analyzeMarkerColors." << std::endl;
        return false;
    }

    cv::Mat leftBlue = blueChannelImage(leftRect);
    cv::Mat rightYellow = yellowChannelImage(rightRect);
    int leftBluePixels = cv::countNonZero(leftBlue);
    int rightYellowPixels = cv::countNonZero(rightYellow);


    if (leftBluePixels > colorThreshold && rightYellowPixels > colorThreshold) {
        isLeftBlue = true;
        return true;
    } else {
        leftBlue = yellowChannelImage(leftRect);
        rightYellow = blueChannelImage(rightRect);
        leftBluePixels = cv::countNonZero(leftBlue);
        rightYellowPixels = cv::countNonZero(rightYellow);

        if (rightYellowPixels > colorThreshold && leftBluePixels > colorThreshold) {
            isLeftBlue = false;
            return true;
        }
    }
    return true;
}



float VisionBasedNavigation::computeSteeringAngle(cv::Mat blueZone, cv::Mat yellowZone, float leftVoltage, float rightVoltage, bool* isLeftBlue, float frontDistance, float gsrBefore) {
    if (blueZone.empty() || yellowZone.empty() || isLeftBlue == nullptr) {
        std::cerr << "Warning: Invalid input data provided to computeSteeringAngle." << std::endl;
        return false; 
    }

    try {
        float cv = visualSteeringAnalysis(blueZone, yellowZone, isLeftBlue, leftVoltage, rightVoltage, frontDistance, gsrBefore);
        return cv;
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV Error: " << e.what() << std::endl;
        return 0.0f; // Continue operation with a default safe value.
    }
}

float VisionBasedNavigation::visualSteeringAnalysis(cv::Mat blueZone, cv::Mat yellowZone, bool* isLeftBlue, float leftVoltage, float rightVoltage, float frontDistance, float gsrBefore) {
    float gsr = 0;  // Initialize the variable to hold the GSR value.
    int bluePixels = cv::countNonZero(blueZone);  // Count the number of non-zero pixels in the blueZone matrix.
    int yellowPixels = cv::countNonZero(yellowZone);  // Count the number of non-zero pixels in the yellowZone matrix.

    float COLOR_THRESHOLD = 5;
    float INPUT_LOWER_BOUND = 0;
    float INPUT_UPPER_BOUND = 1200;
    float OUTPUT_LOWER_BOUND = 0;
    float OUTPUT_UPPER_BOUND = 0.21;

    if (isLeftBlue)  // Check if the blue color is on the left side.
    {
        // Right Turn (Steering angle needs to be negative)
        if (bluePixels >= yellowPixels) {
            gsr = integralSteering(leftVoltage, rightVoltage, frontDistance, gsrBefore) * -1;
        } 
        // Left Turn (Steering angle needs to be positive)
        else if (bluePixels < yellowPixels) {
            gsr = integralSteering(leftVoltage, rightVoltage, frontDistance, gsrBefore);
        }
    }
    // Case where blue color is on the right side
    else {
        // Left Turn (Steering angle needs to be positive)
        if (bluePixels >= yellowPixels) {
            gsr = integralSteering(leftVoltage, rightVoltage, frontDistance, gsrBefore) * -1;
        }
        // Right Turn (Steering angle needs to be positive)
        else if (bluePixels < yellowPixels) {
            gsr = integralSteering(leftVoltage, rightVoltage, frontDistance, gsrBefore);
        }
    }
    return gsr;
}
