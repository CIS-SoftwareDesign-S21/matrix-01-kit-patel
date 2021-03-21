# Lab Parallel Computing
**Tsunkit Lam & Edward Brace**

`SIMD`: Each instruction performs the same operation on multiple streams of data simultaneously. This allows for easy implementation of parallelism, particularly when performing repetitive complex math such as matrix multiplication. SIMD can be implemented even on single-threaded CPUs, with the one core alternating between processing each thread.

`OMP` : OpenMP is a set of compiler directives as well as an API forprograms written in C, C++, or FORTRAN that provides support for parallel programming in shared-memory environments. OpenMP identifies parallel regions as blocks of code that may run in parallel and optimizes them when written according to its standards. Multi-core CPUs are required to executed code optimized using OMP.

`MPI` : Message Passing Interface (MPI) is a communication protocol for parallel programming. MPI is specifically used to allow applications to run in parallel across a number of separate computers connected by a network. Multiple machines - as opposed to multiple cores in one machine - are required for MPI.

`Eddie Brace` : Contributions invloved initial commits to implement SIMD parallelism and extensive changes later on to broaden test cases, optimize MPI implemnentation to meet expected resulted results, and re-configuring labels on graph to reflect accurately the test results.

**Project Life Cycle**
We used Trello to keep track of tasks. I (eddie) have limited experience with Trello but it's very straightforward and easy to use.
Using the Wolfgang cluster made development more onerous as developing using an IDE required commiting changes to Task-Branch every time code was to be tested. This resulted in slower progress and more commits but also encouraged me to become proficient with nano on the server itself.
Testing measured the execution time at intervals of 100 matrices using clocks ticks as a measurementl, translated to seconds for presentation purposes. We used simple loops to process randomly generated matrices of size 1-1000 for each distint approach to matric multiplication. Results were written to a text file and automatically made into a graph using GNUPLot.
Development time was used extensively on both testing and code modofications, which we tended to bounce back and forth between for reasons described above.

`Trello`: 
https://trello.com/b/YSd7MV8e/lab-parallel-computing


`Output graph`:

![Task 5](https://github.com/CIS-SoftwareDesign-S21/matrix-01-kit-patel/blob/task5/out.png)

