#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

Matrix createMatrix(unsigned rows, unsigned columns) {
        Matrix matrix;
        matrix.rows = rows;
        matrix.columns = columns;

        matrix.data = (double*)malloc(rows sizeof(double));

        for (unsigned i = 0; i < rows; i++) {
                matrix.data[i] = (double)malloc(columns * sizeof(double));
        }

        return matrix;
}

void fill_matrix(Matrix matrix) {
        unsigned value = 1;

        for (unsigned i = 0; i < matrix.rows; i++) {
                for (unsigned j = 0; j < matrix.columns; j++) {
                        matrix.data[i][j] = (double)value;
                        value++;
                }
        }
}

double timed_test(int rows1, int columns1, int rows2, int columns2, int which_one) {

        if (columns1 != rows2) {
                printf("Error: Matrices cannot be multiplied. Column of the first matrix must match the row of the second matrix.\n");
                return 0.0;
        }

        Matrix A = createMatrix(rows1, columns1);
        fill_matrix(A);

        Matrix B = createMatrix(rows2, columns2);
        fill_matrix(B);

        clock_t start_time = clock();

        Matrix C = matrix_multiply(A, B);
        switch (which_one) {
        case 1:
            C = matrix_multiply_ijk(A, B);
            break;
        case 2:
            C = matrix_multiply_kij(A, B);
            break;
        case 3:
            C = matrix_multiply_jki(A, B);
            break;
        default:
            printf("Invalid matrix multiplication function selection.\n");
            return 0.0;
}

        clock_t end_time = clock();

        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        //printf("Matrix C (result of multiplication):\n");
        //for (unsigned i = 0; i < C.rows; i++) {
                //for (unsigned j = 0; j < C.columns; j++) {
                        //printf("%.2f ", C.data[i][j]);
                //}
                //printf("\n");
        //}

        printf("Matrix multiplication took %.6f seconds.\n", elapsed_time);

         return elapsed_time;
}

int main(int argc, char* argv[]){

        if(argc != 5){
                printf("Error: Please provide exactly four arguments for matrix dimensions.\n");
                return 1;
        }

        int rows1 = atoi(argv[1]);
        int columns1 = atoi(argv[2]);
        int rows2 = atoi(argv[3]);
        int columns2 = atoi(argv[4]);

        printf("Testing matrix_multiply_ijk:\n");
        double elapsed_time_ijk = timed_test(rows1, columns1, rows2, columns2, 1);

        printf("Testing matrix_multiply_kij:\n");
        double elapsed_time_kij = timed_test(rows1, columns1, rows2, columns2, 2);

        printf("Testing matrix_multiply_jki:\n");
        double elapsed_time_jki = timed_test(rows1, columns1, rows2, columns2, 3);

        return 0;
}
