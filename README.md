Face Recognition using OpenCV
=================

Prerequisites
-------------
###### boost
> C++ utilities package
> http://www.boost.org/ | libboost-dev

###### cmake
> Build management tool; v2.8 or higher recommended.
> http://www.cmake.org/ | cmake

###### opencv
> Opensource computer vision library.
> http://www.samontab.com/web/2014/06/installing-opencv-2-4-9-in-ubuntu-14-04-lts/


Build
-----
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Run Tracker
-----------
Run tracker_demo for face tracking without recognition.
```sh
$ ./tracker_demo
```

Run Trainer
-----------
Run trainer_demo to collect face data. It should be run atleast twice for the classifier to work. After running, enter name and press 'Enter'. Press 'Space' multiple times to capture face data.
```sh
$ ./trainer_demo
```

Run Classifier
--------------
Run classifier_demo to view the face recognition in action.
```sh
$ ./classifier_demo
```