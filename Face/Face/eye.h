#ifndef EYE_H
#define EYE_H

#include <opencv2/opencv.hpp>

class Eye {
private:
    cv::Point position;
    int outerRadius;
    int innerRadius;
    cv::Scalar color;

public:
    Eye(cv::Point pos, int outerR, int innerR, cv::Scalar col);
    void draw(cv::Mat& canvas);
};

#endif
