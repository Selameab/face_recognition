/* 
 * File:   Trainer.cpp
 * Author: ss
 */

#include "Trainer.h"

Trainer::Trainer(string path, string name) {
    face_cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
    storagePath = path + "/" + name;
    if (boost::filesystem::create_directories(boost::filesystem::path(storagePath)))
        cout << "Directory created: [" << storagePath << "]" << endl;
    else if (boost::filesystem::is_directory(storagePath))
        cout << "Directory [" << storagePath << "] already exists." << endl;
    else
        cout << "ERROR: Failed to create [" << storagePath << "]" << endl;
}

Trainer::~Trainer() {
}

string Trainer::addFace(Mat face) {
    resize(face, face, Size(200, 200));
    stringstream path;
    path << storagePath << "/" << time(NULL) << ".jpg";
    imwrite(path.str(), face);

    return path.str();
}

vector<Rect> Trainer::detectFaces(Mat frame) {
    vector<Rect> faces;
    Mat buffer_mat;
    cvtColor(frame, buffer_mat, COLOR_BGR2GRAY);
    equalizeHist(buffer_mat, buffer_mat);
    face_cascade.detectMultiScale(buffer_mat, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
    return faces;
}

