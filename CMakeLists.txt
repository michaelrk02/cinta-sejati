# CMake executable project
cmake_minimum_required(VERSION 3.0)

### CONFIGURATIONS

set(Project "cinta-sejati")

### SETUP

project(${Project})
add_executable(${Project}
    "main.cpp"
)

