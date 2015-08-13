/* 
 * File:   trainer.h
 * Author: ss
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <boost/filesystem.hpp>

using namespace cv;
using namespace std;

class Trainer {
public:
    Trainer(string, string);
    string addFace(Mat);
    virtual ~Trainer();
private:
    string storagePath;
};


