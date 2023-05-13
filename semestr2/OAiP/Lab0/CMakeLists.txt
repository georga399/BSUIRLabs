cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Qt6_DIR C:/Qt/6.4.1/mingw_64/lib/cmake/Qt6)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)
qt_standard_project_setup()

add_executable(zerolab
    src/task1/mouseobserver.h
    src/task1/mouseobserver.cpp
    src/task1/rotatwheel.cpp
    src/task1/rotatwheel.h
    src/task1/widgtask1.h
    src/task1/widgtask1.cpp

    src/task2/widgtask2.h
    src/task2/widgtask2.cpp
    src/task2/figure.h
    src/task2/figure.cpp
    src/task2/ellipse.h
    src/task2/ellipse.cpp
    src/task2/rectangle.h
    src/task2/rectangle.cpp
    src/task2/triangle.h
    src/task2/triangle.cpp
    src/task2/star.h
    src/task2/star.cpp
    src/task2/rhomb.h
    src/task2/rhomb.cpp
    src/task2/square.h
    src/task2/square.cpp
    src/task2/circle.h
    src/task2/circle.cpp
    src/task2/nagon.h
    src/task2/nagon.cpp
    src/task2/pacman.h
    src/task2/pacman.cpp
    src/main.cpp
)

target_link_libraries(zerolab PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)

set_target_properties(zerolab PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)