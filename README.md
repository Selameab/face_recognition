Face Recognition using OpenCV

# Compile

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Run Trainer

Run trainer_demo to collect face data. It should be run atleast twice for the classifier to work. After running, enter name and press 'Enter'. Press 'Space' multiple times to capture face data.

```sh
$ ./trainer_demo
```


# Run Classifier

Run classifier_demo to view the face recognition in action.

```sh
$ ./classifier_demo
```