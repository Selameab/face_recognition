#include "utils/utils.h"
#include "classifier/classifier.h"

#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;

int main(int argc, char* argv[]) {

    Utils::Init();

    const string path = "data/faces";

    // Train classifier using data
    Classifier classifier1;

    // Add people
    boost::filesystem::directory_iterator end_itr;
    for (boost::filesystem::directory_iterator dir_itr(path); dir_itr != end_itr; ++dir_itr) {
        if (boost::filesystem::is_directory(dir_itr->status())) {
            classifier1.addPerson((*dir_itr).path().filename().c_str());
            // Add face of each person
            for (boost::filesystem::directory_iterator file_itr((*dir_itr).path()); file_itr != end_itr; ++file_itr) {
                classifier1.addFace((*dir_itr).path().filename().c_str(), (*file_itr).path().c_str());
            }
        }
    }

    classifier1.train();

    // Display live feed and store faces
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
                int pos_x = max(faces[i].tl().x - 10, 0);
                int pos_y = max(faces[i].tl().y - 10, 0);
                rectangle(frame, faces[i], CV_RGB(100, 100, 255), 1);
                // Identify person and add text to frame
                putText(frame, classifier1.classify(frame(faces[i])), Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 0, 255), 2.0);
            }
            imshow("Live Feed", frame);
        }
        if (keyPressed == 27) break;
    }
    cvReleaseCapture(&capture);
    return 0;
}

