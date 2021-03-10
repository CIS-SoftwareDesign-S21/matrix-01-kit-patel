# Lab Parallel Computing

Tsunkit Lam & Edward Brace


`SIMD`: Each instruction performs the same operation on multiple streams of data simultaneously. This allows for easy implementation of parallelism, particularly when performing repetitive complex math such as matrix multiplication. SIMD can be implemented even on single-threaded CPUs, with the one core alternating between processing each thread.

`OMP` : OpenMP is a set of compiler directives as well as an API forprograms written in C, C++, or FORTRAN that provides support for parallel programming in shared-memory environments. OpenMP identifies parallel regions as blocks of code that may run in parallel and optimizes them when written according to its standards. Multi-core CPUs are required to executed code optimized using OMP.

`MPI` : Message Passing Interface (MPI) is a communication protocol for parallel programming. MPI is specifically used to allow applications to run in parallel across a number of separate computers connected by a network. Multiple machines - as opposed to multiple cores in one machine - are required for MPI.


Trello: 
https://trello.com/b/YSd7MV8e/lab-parallel-computing

#### Task 2:

**RED LINE: SIMD No Optimization**

**BLUE LINE: NonSIMD**

![Task 2](https://github.com/CIS-SoftwareDesign-S21/matrix-01-kit-patel/blob/master/Task2Graph.png)

##### Task 3:

**RED LINE: Vectorized Output**

**BLUE LINE: NonSIMD**

![Task 3](https://github.com/CIS-SoftwareDesign-S21/matrix-01-kit-patel/blob/master/Task3Graph.png)

