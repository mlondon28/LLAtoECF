cmake_minimum_required(VERSION 3.0.0)
project(LLAtoECF VERSION 0.1.0)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_library(readcsv src/csv_utils.cpp)
add_executable(LLAtoECF src/LLAtoECF.cpp)
target_link_libraries(LLAtoECF readcsv)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)