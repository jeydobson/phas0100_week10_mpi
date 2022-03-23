#include <mpi.h>
// Next line tells CATCH we will use our own main function
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE("Just test I exist") {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // EXERCISE 1.7 solution: note to see the following you will
    // need to run with catch2 -s option so that information on 
    // tests that pass is printed to screen i.e. as:
    // mpiexec ./hello/helloCatch -s 
    int length;
    char name[256];
    MPI_Comm_get_name(MPI_COMM_WORLD, name, &length);
    INFO("Comm name is "<< name << ", it's "<< length << " chars long");
    // alternatively you could add another check to check that name
    // is equal to "MPI_COMM_WORLD" 

    CHECK(size > 0); CHECK(rank >= 0);
}

int main(int argc, char * argv[]) {
    MPI_Init(&argc, &argv);
    int result = Catch::Session().run(argc, argv);
    MPI_Finalize();
    return result;
}