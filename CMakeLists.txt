project(Week10MPIExercises)
cmake_minimum_required(VERSION 3.16)

find_package(MPI REQUIRED)
include_directories(${MPI_CXX_INCLUDE_PATH})

include_directories(catch)
add_subdirectory(hello)
add_subdirectory(point2point)
add_subdirectory(collective)