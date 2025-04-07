#pragma once
#include<opencv2/opencv.hpp>
#include <string>

class NeutralFace {
public:
	NeutralFace();
	void draw(cv::Mat& image, int frameCount);

private:
	int blinkStartFrame = -1000;
	int blinkInterval = 120;
	int blinkDuration = 12;
};