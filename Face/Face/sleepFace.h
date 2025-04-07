#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

struct Z {
    cv::Point2f pos;
    float scale;
    int alpha;
    int lifetime;
};

class SleepFace {
public:
    SleepFace();
    void draw(cv::Mat& image, int frameCount);

private:
    std::vector<Z> zzz;
};
