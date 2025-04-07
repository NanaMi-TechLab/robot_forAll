#include "sleepFace.h"
#include <cmath>
#include <iostream>

SleepFace::SleepFace() {}

void SleepFace::draw(cv::Mat& image, int frameCount) {
    int offsetY = static_cast<int>(std::sin(frameCount * 0.05f) * 20);

    // Gesicht zeichnen
    cv::ellipse(image, cv::Point(500, 300 + offsetY), cv::Size(60, 30), 0, 0, 180, cv::Scalar(255, 255, 255), 10);
    cv::ellipse(image, cv::Point(780, 300 + offsetY), cv::Size(60, 30), 0, 0, 180, cv::Scalar(255, 255, 255), 10);
    cv::ellipse(image, cv::Point(610, 360 + offsetY), cv::Size(30, 20), 0, 0, 180, cv::Scalar(255, 255, 255), 10);
    cv::ellipse(image, cv::Point(670, 360 + offsetY), cv::Size(30, 20), 0, 0, 180, cv::Scalar(255, 255, 255), 10);

    // Zzz animieren
    for (auto& z : zzz) {
        cv::Scalar color(255, 255, 255); // weiﬂ
        cv::putText(image, "Z", z.pos, cv::FONT_HERSHEY_SIMPLEX, z.scale, color, 2, cv::LINE_AA);

        z.scale += 0.02f;
        z.pos.x += 1.5f;
        z.pos.y -= 1.0f;
        z.alpha -= 4;
        z.lifetime--;
    }

    // Entferne tote Zs
    zzz.erase(std::remove_if(zzz.begin(), zzz.end(), [](const Z& z) {
        return z.alpha <= 0 || z.lifetime <= 0;
        }), zzz.end());

    // Neues Z erzeugen nur bei Ausatmen
    float breath = std::sin(frameCount * 0.05f);
    if (breath < 0 && frameCount % 20 == 0) {
        zzz.push_back(Z{ cv::Point2f(850, 280 + offsetY), 0.6f, 255, 60 });
        std::cout << "Z hinzugef¸gt bei Frame " << frameCount << std::endl;
    }
}
