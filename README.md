# PHAS0100 Week 10 MPI exercises
Repository with exercises for PHAS0100 week 10 live class. 

The relevant apt-get install commands for OpenMPI libraries have been added to the https://github.com/UCL/rc-cpp-vscode-dev-container but if you are using an older version and want to install the openmpi libraries in a running container then you can run the following:
``` shell
apt-get update
apt-get install openmpi-bin libopenmpi-dev
```

Before attempting to complete the exercises you need to ensure the openmpi libraries were installed on your system with:
``` shell
mpiexec --version
mpicxx --version
```

In-code HANDSON comments indicate where changes need to be made to complete the tasks for each of the four tasks.