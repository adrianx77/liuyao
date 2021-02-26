cmake_minimum_required(VERSION 3.20)
project(LiuYao)
#set the source directory
file(GLOB_RECURSE SOURCES src/*/*.cxx)
add_executable(LiuYao main.cxx ${SOURCES})