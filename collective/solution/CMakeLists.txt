add_executable(scatter scatter.cpp)
target_link_libraries(scatter ${MPI_CXX_LIBRARIES})

add_executable(reduce reduce.cpp)
target_link_libraries(reduce ${MPI_CXX_LIBRARIES})