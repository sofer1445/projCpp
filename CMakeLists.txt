cmake_minimum_required(VERSION 3.25)
project(proj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/Users/sofer/Downloads/SDL2-devel-2.28.4-mingw/SDL2-2.28.4/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(proj main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})


