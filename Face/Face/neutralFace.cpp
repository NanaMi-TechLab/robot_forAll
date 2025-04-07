#include "neutralFace.h"

NeutralFace::NeutralFace() {
	/*windowsName = "NeutralFace Output";
	cv::namedWindow(windowsName, cv::WINDOW_AUTOSIZE);*/
}

void NeutralFace::draw(cv::Mat& image, int frameCount) {
	// Blinzelanimation
	if (frameCount - blinkStartFrame > blinkInterval + blinkDuration) {
		blinkStartFrame = frameCount;
}
	int blinkProgress = frameCount - blinkStartFrame;
	float blinkFactor = 1.0f;

	if (blinkProgress < blinkDuration) {
		float t = blinkProgress / static_cast<float>(blinkDuration);
		blinkFactor = std::sin(t * CV_PI);

	}
	// Berechne Augen- und Pupillenhöhe je nach Blinkzustand
	int eyeHeight = static_cast<int>(80 * blinkFactor);
	int pupilHeight = static_cast<int>(40 * blinkFactor);
	//Auge
	cv::circle(image, cv::Point(500, 300), 80, cv::Scalar(255, 255, 255), 10);
	cv::circle(image, cv::Point(780, 300), 80, cv::Scalar(255, 255, 255), 10);

	if (eyeHeight > 10) {
//Pupille
	cv::circle(image, cv::Point(500, 300), 40, cv::Scalar(255, 255, 255), -1);
	cv::circle(image, cv::Point(780, 300), 40, cv::Scalar(255, 255, 255), -1);

	}
	
	//Augenbraun
	cv::line(image, cv::Point(440, 200), cv::Point(560, 200), cv::Scalar(255, 255, 255), 8);
	cv::line(image, cv::Point(720, 200), cv::Point(840, 200), cv::Scalar(255, 255, 255), 8);

	cv::ellipse(image, cv::Point(610, 400 ), cv::Size(30, 20), 0, 0, 180, cv::Scalar(255, 255, 255), 10);
	cv::ellipse(image, cv::Point(670, 400), cv::Size(30, 20), 0, 0, 180, cv::Scalar(255, 255, 255), 10);

	/*cv::imshow(windowsName, image);
	cv::waitKey(0);*/
}