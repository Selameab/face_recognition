/* 
 * File:   classifier.cpp
 * Author: ss
 */

#include "classifier.h"

Classifier::Classifier() {
    faceRecognizer = createFisherFaceRecognizer();

}

void Classifier::addPerson(string name) {
    name_to_label.insert(std::pair<string, int>(name, name_to_label.size()));
    label_to_name.insert(std::pair<int, string>(name_to_label.size() - 1, name));
}

void Classifier::addFace(string name, string img_path) {
    labels.push_back(name_to_label[name]);
    faces.push_back(imread(img_path, 0));
}

void Classifier::train(void) {
    faceRecognizer->train(faces, labels);
}

string Classifier::classify(Mat face) {
    Mat buffer_mat;
    cvtColor(face, buffer_mat, COLOR_BGR2GRAY);
    equalizeHist(buffer_mat, buffer_mat);
    cv::resize(buffer_mat, buffer_mat, Size(200, 200), 1.0, 1.0, INTER_CUBIC);
    return label_to_name[faceRecognizer->predict(buffer_mat)];
}