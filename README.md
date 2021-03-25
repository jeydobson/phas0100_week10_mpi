# PHAS0100 Week 10 exercises: OpenMPI
Repository with exercises for PHAS0100 week 10 live class. 

### Environment setup

For convenience this repository includes an updated .devcontainer/Dockerfile with the relevant apt-get install commands for OpenMPI libraries included. If you are using your own Dockerfile or are not using Docker at all then you can install the openmpi libraries (on Ubuntu 20.04) with:
``` shell
apt-get update
apt-get install openmpi-bin libopenmpi-dev
```

Before attempting to complete the exercises you need to ensure the openmpi libraries were installed on your system with:
``` shell
mpiexec --version
mpicxx --version
```

### Completing the exercises

See the class HackMD document for detailed steps:
* In-code HANDSON comments indicate where changes need to be made to complete the tasks for each of the four tasks.
* To speed up compilation comment out relevant add_subdirectory commands in the top-level CMakeLists.txt file to speed up compilation when working on one exercise.
* Order of tasks:
   * `hello`
   * `point2point`
   * `collective`