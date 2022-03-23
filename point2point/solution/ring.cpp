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

      // EXERCISE 5 solution
      if (rank % 2 == 0) {
        int error = MPI_Ssend(
          &message, 1, MPI_INT, left, rank, MPI_COMM_WORLD);
        REQUIRE(error == MPI_SUCCESS);

        error = MPI_Recv(
          &received, 1, MPI_INT, right, right, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        REQUIRE(error == MPI_SUCCESS);
      }
      if (rank % 2 == 1) {

        int error = MPI_Recv(
          &received, 1, MPI_INT, right, right, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        REQUIRE(error == MPI_SUCCESS);

        error = MPI_Ssend(
          &message, 1, MPI_INT, left, rank, MPI_COMM_WORLD);
        REQUIRE(error == MPI_SUCCESS);

        // EXERCISE 5.6:
        // The order of these MPI_Recv and MPI_Ssend commands matters. 
        // MPI_Ssend is synchonous blocking so will get deadlock if it occurs before 
        // the MPI_Recv command: both even and odd processes will MPI_Ssend and wait for 
        // a receipt - this will never happen as neither progress to the MPI_Recv
      }
      REQUIRE( received == right*right );
    }

    SECTION("Asynchronous") {
      // EXERCISE 6 solution:
      MPI_Request send_req;
      // Everyone sets up their messages to send
      int error = MPI_Isend(
        &message, 1, MPI_INT, left, rank, MPI_COMM_WORLD, &send_req);
      REQUIRE(error == MPI_SUCCESS);

      // Recv acts as our sync-barrier
      error = MPI_Recv(
        &received, 1, MPI_INT, right, right, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      REQUIRE(error == MPI_SUCCESS);

      // But let's check our send completed:
      int completed;
      error = MPI_Test(&send_req, &completed, MPI_STATUS_IGNORE);
      REQUIRE(error ==  MPI_SUCCESS);
      REQUIRE(completed == true);

      REQUIRE( received == right*right );
    }

      SECTION("Sendreceive") {
        // EXERCISE 7 solution
        int error = MPI_Sendrecv(
          &message, 1, MPI_INT, left, rank,
          &received, 1, MPI_INT, right, right,
          MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        REQUIRE(error ==  MPI_SUCCESS);

        REQUIRE( received == right*right );
    }
}

int main(int argc, char * argv[]) {
    MPI_Init(&argc, &argv);
    int result = Catch::Session().run(argc, argv);
    MPI_Finalize();
    return result;
}