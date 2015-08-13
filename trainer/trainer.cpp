/* 
 * File:   trainer.cpp
 * Author: ss
 */

#include "trainer.h"

Trainer::Trainer(string path, string name) {    
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