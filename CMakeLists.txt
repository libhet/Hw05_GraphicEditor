cmake_minimum_required(VERSION 3.9)
project(Hw05_GraphicEditor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hw05_GraphicEditor main.cpp src/GraphicsModel.h src/GraphicsView.h src/GraphicsController.h src/GraphicsController.cpp src/GraphicsModel.cpp src/GraphicsView.cpp)

#enable_testing()
#include(CTest)
#add_subdirectory(tests)