/** 
 * Incomplete program to multiply a matrix times a matrix using both
 * MPI to distribute the computation among nodes and OMP
 * to distribute the computation among threads.
 */

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#define min(x, y) ((x)<(y)?(x):(y))

#include "mat.h"

int main(int argc, char* argv[])
{
    int nrows, ncols;
    double *aa;	/* the A matrix */
    double *bb;	/* the B matrix */
    double *cc1;	/* A x B computed using the omp-mpi code you write */
    double *cc2;	/* A x B computed using the conventional algorithm */
    int myid, numprocs;
    double starttime, endtime;
    MPI_Status status;

    /* insert other global variables here */

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    if (argc > 1) {
        b = (double*)malloc(sizeof(double) * ncols);
        c = (double*)malloc(sizeof(double) * nrows);
        buffer = (double*)malloc(sizeof(double) * ncols);
        master = 0;

        if (myid == master) {
            // Master Process
            a = gen_matrix(nrows, ncols);
            numsent = 0;
           // broadcast the entire matrix b to all slave processes
           MPI_Bcast(b, ncols, MPI_DOUBLE, master, MPI_COMM_WORLD);
           // iterate over each row in matrix a/slave processes
           for (i = 0; i < min(numprocs-1, nrows); i++) {
                // add current row in a to buffer
                for (j = 0; j < ncols; j++) 
                     buffer[j] = a[i * ncols + j];
                // send just one row from a to the slave processes
                MPI_Send(buffer, ncols, MPI_DOUBLE, i+1, i+1, MPI_COMM_WORLD);
           }
        }
    
        else {
            // Slave Code 
            // here is where the slave processes listen for the broadcast (specifies master as the sender)
            // they're receiving the matrix b
            MPI_Bcast(b, ncols, MPI_DOUBLE, master, MPI_COMM_WORLD);
            if (myid <= nrows) {
                while(1) {
                    MPI_Recv(buffer, ncols, MPI_DOUBLE, master, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
                    if (status.MPI_TAG == 0)
                               break;

                    row = status.MPI_TAG;

                    //TODO calculate row buffer * matrix b here and put into row result

                    //TODO send the row result back to master
                }

             }

        }
    }
        else {
        fprintf(stderr, "Usage matrix_times_vector <size>\n");
    }
    MPI_Finalize();
    return 0;
}
