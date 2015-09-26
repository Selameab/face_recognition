/* 
 * File:   tracker_demo.cpp
 * Author: ss
 */

#include "utils/utils.h"
#include "trainer/trainer.h"

int main(int argc, char* argv[]) {

    Utils::Init();

    CvCapture* capture = cvCreateCameraCapture(0);
    Mat frame;
    vector<Rect> faces;
    int keyPressed;
    while (true) {
        frame = cvQueryFrame(capture);
        keyPressed = cvWaitKey(30) & 0xFF;
        if (!frame.empty()) {
            faces = Utils::detectFaces(frame);
            for (int i = 0; i < faces.size(); i++) {
                rectangle(frame, faces[i], CV_RGB(100, 100, 255), 1);
            }
            imshow("Live Feed", frame);
        }
        if (keyPressed == 27) break;
    }

    cvReleaseCapture(&capture);
    return 0;
}

