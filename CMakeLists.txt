cmake_minimum_required(VERSION 3.15)
project(Box2DDemo LANGUAGES CXX)

find_package(box2d REQUIRED)

add_executable(box2d_demo main.cpp)

target_link_libraries(box2d_demo PRIVATE box2d::box2d)

set_target_properties(box2d_demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                            ${CMAKE_BINARY_DIR}/bin)
