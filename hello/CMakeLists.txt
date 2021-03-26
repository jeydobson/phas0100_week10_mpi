add_executable(hello hello.cpp)
target_link_libraries(hello ${MPI_CXX_LIBRARIES})

add_executable(helloCatch helloCatch.cpp)
target_link_libraries(helloCatch ${MPI_CXX_LIBRARIES})
