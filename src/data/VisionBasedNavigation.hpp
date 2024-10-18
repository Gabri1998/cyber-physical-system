#ifndef VISIONBASEDNAVIGATION_HPP
#define VISIONBASEDNAVIGATION_HPP

#include <opencv2/opencv.hpp>
#include "IntegralSteering.hpp"

class VisionBasedNavigation {
public:
    VisionBasedNavigation(float colorThreshold = 300, float voltageThreshold = 0.5);
    bool analyzeMarkerColors(const cv::Mat& blueChannelImage, const cv::Mat& yellowChannelImage, const cv::Rect& leftRect, const cv::Rect& rightRect, bool& isLeftBlue);
    float computeSteeringAngle(cv::Mat blueZone, cv::Mat yellowZone, float leftVoltage, float rightVoltage, bool* isLeftBlue, float distance, float gsrBefore);

private:
    float visualSteeringAnalysis(cv::Mat blueZone, cv::Mat yellowZone, bool* isLeftBlue, float leftVoltage, float rightVoltage, float frontDistance, float gsrBefore);
    float infraredSteeringCorrection(float leftVoltage, float rightVoltage);

    float colorThreshold;
    float voltageThreshold;
};

#endif // VISIONBASEDNAVIGATION_HPP
