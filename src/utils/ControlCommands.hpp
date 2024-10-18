#ifndef CONTROL_COMMANDS_HPP
#define CONTROL_COMMANDS_HPP

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
#include "opendlv-standard-message-set.hpp"

class ControlCommands {
public:
    void evaluateSteeringData(cv::Mat centerBlue, cv::Mat centerYellow, const opendlv::proxy::GroundSteeringRequest& requestedSteering, bool isBlueOnLeft);
    void logSteeringResults(float bluePixelCount, float yellowPixelCount, float requestedSteering, float computedSteering);
    void assessSteeringError(float requestedSteering, float computedSteering);

private:
    float calculatePixelCount(cv::Mat image);
};

#endif // CONTROL_COMMANDS_HPP
