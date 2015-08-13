/* 
 * File:   classifier.h
 * Author: ss
 */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <boost/filesystem.hpp>

using namespace cv;
using namespace std;

class Classifier {
public:
    Classifier();
    void addPerson(string);
    void addFace(string, string);
    void train(void);
    string classify(Mat);
private:
    map<string, int> name_to_label;
    map<int, string> label_to_name;
    vector<Mat> faces;
    vector<int> labels;
    Ptr< FaceRecognizer> faceRecognizer;
};


