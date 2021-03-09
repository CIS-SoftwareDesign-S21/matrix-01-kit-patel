#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mat.h"

#define MAT_SIZE 5

int test_unoptimized(double *a, int arows, int acols,
                     double *b, int brows, int bcols,
                     double *c_actual) {
    double *c_calc = malloc(MAT_SIZE * MAT_SIZE * sizeof(double));

    mmult(c_calc, a, MAT_SIZE, MAT_SIZE, b, MAT_SIZE, MAT_SIZE);

    int are_same = compare_matrices(c_actual, c_calc, MAT_SIZE, MAT_SIZE);

    free(c_calc);

    return are_same;
}

int main(void) {
    
    FILE * output = fopen( "Task3-nonSIMD-output.txt", "w" );
    
    for( int i = 0; i < 101; i++ ) {
        
        clock_t startTime = clock();
        
        double * a = gen_matrix( i, i );
        double * b = gen_matrix( i, i );
        double * result = malloc( i * i * sizeof( double ) );
        
        mmult( result, a, i, i, b, i, i );
        clock_t endTime = clock();
        free( result );
        
        long double time = (endTime - startTime);
        fprintf( output, "%d,%Lf,", i, time );
        
    }
    fclose( output );
    
    output = fopen( "Task3-Actual-Non-VectorizedSIMD-output.txt", "w" );
    for( int j = 0; j < 101; j++ ) {
        
        clock_t startTime = clock();
        
        double * a = gen_matrix( j, j );
        double * b = gen_matrix( j, j );
        double * result = malloc( j * j * sizeof( double ) );
        
        mmult_simd( result, a, j, j, b, j, j );
        clock_t endTime = clock();
        free( result );
        
        long double time = (endTime - startTime);
        fprintf( output, "%d,%Lf,", j, time );
        
    }
    fclose( output );
    
}
