#include <mpi.h>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE("Collective communications") {

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    SECTION("Collective scatter") {
      std::string const message = "This message is going to come out in separate channels";
      if (message.size() < (unsigned)size) return;
      int N = message.size() / size;

      char buffer[256];
      // HANDSON 3.2: use the MPI_Scatter method to split the message across all processes
 
      CHECK(message.substr(rank*N, N) == std::string(buffer, N));
    }
}

int main(int argc, char * argv[]) {
    MPI_Init(&argc, &argv);
    int result = Catch::Session().run(argc, argv);
    MPI_Finalize();
    return result;
}