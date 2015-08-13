/* 
 * File:   utils.h
 * Author: ss
 */
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;
using namespace std;

class Utils {
public:
    static void Init();
    static vector<Rect> detectFaces(Mat);
private:
    static CascadeClassifier face_cascade;
};


