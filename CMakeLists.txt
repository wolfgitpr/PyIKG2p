cmake_minimum_required(VERSION 3.17)
project(PyIKG2p)

add_subdirectory(IkG2p)
add_subdirectory(pybind11)

find_package(pybind11 CONFIG)

include_directories(PyIKG2p IkG2p/cpp/include IkG2p/cpp/lib)

pybind11_add_module(PyIKG2p src/wrapper.cpp)

target_link_libraries(PyIKG2p PUBLIC IKg2p)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(PyIKG2p
        PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
