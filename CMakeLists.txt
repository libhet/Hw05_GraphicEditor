cmake_minimum_required(VERSION 3.9)
project(Hw05_GraphicEditor)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Hw05_GraphicEditor

        main.cpp

        src/graphics_types.h
        src/graphics_model.h
        src/graphics_view.h
        src/graphics_controller.h
        src/graphics_export.h
        src/graphics_import.h
        src/graphics_export/export_svg.h
        src/graphics_import/import_svg.h
        src/graphics_export/export_my_format.h
        src/graphics_import/import_my_format.h

        src/graphics_controller.cpp
        src/graphics_model.cpp
        src/graphics_view.cpp
        src/graphics_export.cpp
        src/graphics_import.cpp
        src/graphics_export/export_svg.cpp
        src/graphics_import/import_svg.cpp
        src/graphics_export/export_my_format.cpp
        src/graphics_import/import_my_format.cpp
        src/graphics_types.cpp)

#enable_testing()
#include(CTest)
#add_subdirectory(tests)