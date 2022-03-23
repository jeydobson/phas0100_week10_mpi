#include <mpi.h>
// Next line tells CATCH we will use our own main function
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE("Ring communications") {

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    REQUIRE(size >= 4);

    int message = rank*rank;
    int received = -7;

    // Define the ring
    int left = rank - 1;
    int right = rank + 1;
    if (rank == 0) {
      left = size - 1;
    }
    if (rank == size - 1){
      right = 0;
    }

    SECTION("Blocking synchronous") {

      if (rank % 2 == 0) {
        // EXERCISE 5.2: implement MPI_Ssend to send message from current process to the one on its left
        // make sure to include a unit test REQUIRE to check the return code

        // EXERCISE 5.3: implement MPI_Recv for this process to recieve message from process on right
        // make sure to include a unit test REQUIRE to check the return code
      }
      if (rank % 2 == 1) {
        // EXERCISE 5.4: as above implement MPI_Recv first

        // EXERCISE 5.5: then MPI_Ssend

        // EXERCISE 5.6: try swapping the order of 5.4 and 5.5. Why is the order important and what are the consequences?
      }
      // This check should pass when 5.2-5.5 are implemented
      REQUIRE( received == right*right );
    }

    SECTION("Asynchronous") {

      MPI_Request send_req;
      // EXERCISE 6.1: now use MPI_Isend to send for all processes
      // remember to pass it a reference to the send_req below

      // EXERCISE 6.2: now setup a MPI_Recv. This will act 
      // as the sync-barrier

      // But let's check our send completed:
      int completed;
      // EXERCISE 6.3: implement an MPI_Test to check whether the send 
      // completed based on the MPI_Request send_req handle and pass it
      // a reference to int completed to fill the result into. 
      // Because MPI_Recv as a sync-barrier completed should always be true.

      // This check should pass when 6.3-6.3 are implemented
      REQUIRE( received == right*right );
    }

      SECTION("Sendreceive") {

        // EXERCISE 7.1: use MPI_Sendrecv to achieve the same as above but now in a 
        // single command

        // Once 7.1 is implemented this check should pass
        REQUIRE( received == right*right );
    }
}

int main(int argc, char * argv[]) {
    MPI_Init(&argc, &argv);
    int result = Catch::Session().run(argc, argv);
    MPI_Finalize();
    return result;
}