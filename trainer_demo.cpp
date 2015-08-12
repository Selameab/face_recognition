#include "Trainer.h"

int main(int argc, char* argv[]) {

    // Get Name
    string name;
    cout << "Name: ";
    cin >> name;

    Trainer trainer1("data/faces", name);

    // Display live feed and store faces
    CvCapture* capture = cvCreateCameraCapture(0);
    Mat frame;
    vector<Rect> faces;
    int keyPressed;
    while (true) {
        frame = cvQueryFrame(capture);
        keyPressed = cvWaitKey(30) & 0xFF;
        if (!frame.empty()) {
            faces = trainer1.detectFaces(frame);
            if (keyPressed == 32) {
                if (faces.size() == 0)
                    cout << "Error: No face found in frame\n" << endl;
                else if (faces.size() == 1)
                    cout << "File saved:" << trainer1.addFace(frame(faces[0])) << endl;
                else
                    cout << "Error: Multiple faces found in frame\n" << endl;
            }
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

