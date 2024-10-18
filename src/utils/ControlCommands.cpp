#include "ControlCommands.hpp"

void ControlCommands::evaluateSteeringData(
        cv::Mat centerBlue,
        cv::Mat centerYellow,
        const opendlv::proxy::GroundSteeringRequest& requestedSteering,
        bool isLeftBlue
) {
    int bluePixelAmount = cv::countNonZero(centerBlue);
    int yellowPixelAmount = cv::countNonZero(centerYellow);
    bool hasbluePixelCount = bluePixelAmount > 250;
    bool hasyellowPixelCount = yellowPixelAmount > 250;
    bool hasValidGroundSteering = false;

    static int blueTurnsCorrectCount = 0;
    static int yellowTurnsCorrectCount = 0;
    static int blueTurnsOnlyGSRCount = 0;
    static int blueTurnsOnlyAlgorithmCount = 0;
    static int yellowTurnsOnlyAlgorithmCount = 0;
    static int yellowTurnsOnlyGSRCount = 0;
    static int noBlueNoTurnsCount = 0;
    static int noYellowNoTurnsCount = 0;

    if (isLeftBlue) {
        hasValidGroundSteering = (requestedSteering.groundSteering() < 0);
    } else {
        hasValidGroundSteering = (requestedSteering.groundSteering() > 0);
    }

    if (hasbluePixelCount && hasValidGroundSteering) {
        blueTurnsCorrectCount++;
    } else if (hasbluePixelCount && !hasValidGroundSteering) {
        blueTurnsOnlyAlgorithmCount++;
    } else if (!hasbluePixelCount && hasValidGroundSteering) {
        blueTurnsOnlyGSRCount++;
    } else {
        noBlueNoTurnsCount++;
    }

    hasValidGroundSteering = false;

    if (isLeftBlue) {
        hasValidGroundSteering = (requestedSteering.groundSteering() > 0);
    } else {
        hasValidGroundSteering = (requestedSteering.groundSteering() < 0);
    }

    if (hasyellowPixelCount && hasValidGroundSteering) {
        yellowTurnsCorrectCount++;
    } else if (hasyellowPixelCount && !hasValidGroundSteering) {
        yellowTurnsOnlyAlgorithmCount++;
    } else if (!hasyellowPixelCount && hasValidGroundSteering) {
        yellowTurnsOnlyGSRCount++;
    } else {
        noYellowNoTurnsCount++;
    }
}

void ControlCommands::logSteeringResults(float bluePixelCount, float yellowPixelCount, float requestedSteering, float computedSteering) {
    std::ofstream outputFile;
    outputFile.open("/host/res.csv", std::ios_base::app);
    outputFile << bluePixelCount << "," << yellowPixelCount << "," << requestedSteering << "," << computedSteering << "\n";
    outputFile.close();
}

void ControlCommands::assessSteeringError(float requestedSteering, float computedSteering) {
    static float totalFrames = 0;
    static float correctFrames = 0;

    float error = ((fabs(requestedSteering - computedSteering)) / fabs(requestedSteering)) * 100;

    if (requestedSteering == 0) {
        error = fabs(requestedSteering - computedSteering);
    }

    std::cout << "requestedSteering: " << requestedSteering << std::endl;
    std::cout << "computedSteering: " << computedSteering << std::endl;
    std::cout << "Error: " << error << std::endl;

    if (requestedSteering != 0 && error <= 30) {
        correctFrames++;
    } else if (requestedSteering == 0 && fabs(requestedSteering - computedSteering) <= 0.05) {
        correctFrames++;
    }

    totalFrames++;
    std::cout << "Frame Stats: " << correctFrames << "/" << totalFrames << "\t" << ((correctFrames / totalFrames) * 100) << " %" << std::endl;
}
