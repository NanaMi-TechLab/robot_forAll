// control.h
#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include "sleepFace.h"
#include "neutralFace.h"

class Control {
public:
    Control();
    void showControllerUI();
    void run();

private:
    std::string windowsName;
	SleepFace sleepFace;
	NeutralFace neutralFace;
    int currentMode;
};
