project(Week10MPIExercises)
cmake_minimum_required(VERSION 3.16)

# FindMPI should find the MPI C++ and C compiler wrappers
# which take care of all compile and link options so no need
# for additional target_link_libraries etc later on 
find_package(MPI REQUIRED)
if(NOT DEFINED MPI_CXX_COMPILER)
    message(FATAL_ERROR "find_package(MPI) cannot find the C++ wrapper")
endif()
message("-- Using MPI C++ compiler wrapper: ${MPI_CXX_COMPILER}")

include_directories(catch)
add_subdirectory(hello)
add_subdirectory(point2point)
add_subdirectory(collective)