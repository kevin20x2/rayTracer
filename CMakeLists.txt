
set(CMAKE_GENERATOR "Unix Makefiles")
cmake_minimum_required(VERSION 3.0)
project(RayTracer)


set(SOURCE main.cpp BaseObject.cpp TracerScene.cpp )
aux_source_directory(. DIRSRCS)
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(RayTracer "${DIRSRCS}")