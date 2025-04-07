// control.cpp
#include "control.h"
#include "sleepFace.h"
#include "neutralFace.h"

Control::Control() {
    windowsName = "Controller";
    currentMode = 1;
    cv::namedWindow(windowsName, cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Face Output", cv::WINDOW_AUTOSIZE);
   
}

void Control::showControllerUI() {
    cv::Mat controllerUI(200, 400, CV_8UC3, cv::Scalar(100, 100, 100)); // grauer Hintergrund
    cv::putText(controllerUI, "1= Schlafendes Gesiche", cv::Point(50, 100), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
	cv::putText(controllerUI, "2= Neutrales Gesicht", cv::Point(50, 150), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
    cv::putText(controllerUI, "ESC= Exit", cv::Point(50, 200), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
    cv::imshow(windowsName, controllerUI);
}

void Control::run() {
    showControllerUI();
    int frameCount = 0;

    while (true) {
		cv::Mat output(720, 1280, CV_8UC3, cv::Scalar(0, 0, 0));

        if (currentMode ==1) {
            sleepFace.draw(output,frameCount); // Gesicht mit Animation
        }
        else if (currentMode == 2) {
            neutralFace.draw(output,frameCount);      // Statisches Gesicht
        }
        cv::imshow("Face Output", output);

        int key = cv::waitKey(30); // ~30 FPS

        if (key == '1') currentMode = 1;
        else if (key == '2') currentMode = 2;
        else if (key == 27) break;


        frameCount++;

    }
}
