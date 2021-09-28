cmake_minimum_required(VERSION 3.0.0)
project(LLAtoECF VERSION 0.1.0)

set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_VERSION "9.3.0")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_library(readcsv src/csv_utils.cpp)
add_library(LLAtoECF src/LLAtoECF.cpp)
target_link_libraries(LLAtoECF readcsv)

add_executable(interpolateVelocity src/interpolateVelocity.cpp)
target_link_libraries(interpolateVelocity LLAtoECF)