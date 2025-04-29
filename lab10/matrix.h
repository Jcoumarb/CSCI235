#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    unsigned rows;
    unsigned columns;
    double ** data;
} Matrix;

Matrix create_matrix(unsigned rows, unsigned columns);

Matrix matrix_multiply(Matrix A, Matrix B);
Matrix matrix_multiply_ijk(Matrix A, Matrix B);
Matrix matrix_multiply_kij(Matrix A, Matrix B);
Matrix matrix_multiply_jki(Matrix A, Matrix B);

void print_matrix(Matrix);

void free_matrix(Matrix);

#endif
