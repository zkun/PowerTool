cmake_minimum_required(VERSION 3.16)

project(PowerTool VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(power main.cpp)

target_link_libraries(power PRIVATE Qt::Widgets)
