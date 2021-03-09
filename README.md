# Lab Parallel Computing

Tsunkit Lam & Edward Brace


`SIMD`: Each instruction performs the same operation on
        multiple streams of data simultaneously. This 
        allows for easy implementation of parallelism, 
        particularly when performing repetitive complex 
        math such as matrix multiplication.

`OMP` : OpenMP is a set of compiler directives as well as an API for
        programs written in C, C++, or FORTRAN that provides support 
        for parallel programming in shared-memory environments. 
        OpenMP identifies parallel regions as blocks of code that may 
        run in parallel and optimizes them when written according to its standards.

`MPI` : Message Passing Interface (MPI) is a communication protocol for 
        parallel programming. MPI is specifically used to allow applications 
        to run in parallel across a number of separate computers connected 
        by a network.
