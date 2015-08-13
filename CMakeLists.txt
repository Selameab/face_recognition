cmake_minimum_required(VERSION 2.6)
set (PROJECT_NAME "face_recognition")
project(${PROJECT_NAME})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(Boost COMPONENTS system filesystem REQUIRED)

include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/utils")
include_directories ("${PROJECT_SOURCE_DIR}/trainer")
include_directories ("${PROJECT_SOURCE_DIR}/classifier")
add_subdirectory (utils)
add_subdirectory (trainer)
add_subdirectory (classifier)
set (EXTRA_LIBS ${EXTRA_LIBS} utils trainer classifier)

add_executable (trainer_demo trainer_demo.cpp ${EXTRA_LIBS})
target_link_libraries (trainer_demo  ${EXTRA_LIBS})
target_link_libraries(trainer_demo ${OpenCV_LIBS})
target_link_libraries(trainer_demo ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

add_executable (classifier_demo classifier_demo.cpp ${EXTRA_LIBS})
target_link_libraries (classifier_demo  ${EXTRA_LIBS})
target_link_libraries(classifier_demo ${OpenCV_LIBS})
target_link_libraries(classifier_demo ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

