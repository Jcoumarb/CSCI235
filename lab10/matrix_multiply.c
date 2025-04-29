#include "matrix.h"
#include <stdlib.h>
Matrix matrix_multiply(Matrix A, Matrix B) {
        if (A.columns != B.rows) {
                exit(1);
        }

        unsigned m = A.rows;
        unsigned n = A.columns;
        unsigned p = B.columns;

        Matrix C;
        C.rows = m;
        C.columns = p;

        C.data = (double*)malloc(m sizeof(double));

        for (unsigned i = 0; i < m; i++) {
                C.data[i] = (double)malloc(p * sizeof(double));
        }


        for (unsigned i = 0; i < m; i++) {
                for (unsigned j = 0; j < p; j++) {
                        C.data[i][j] = 0.0;
                        for (unsigned k = 0; k < n; k++) {
                                C.data[i][j] += A.data[i][k] * B.data[k][j];
                        }
                }
        }

        return C;
}
Matrix matrix_multiply_ijk(Matrix A, Matrix B) {
    if (A.columns != B.rows) {
        exit(1);
    }

    unsigned m = A.rows;
    unsigned n = A.columns;
    unsigned p = B.columns;

    Matrix C;
    C.rows = m;
    C.columns = p;

    C.data = (double*)malloc(m sizeof(double));

    for (unsigned i = 0; i < m; i++) {
        C.data[i] = (double)malloc(p * sizeof(double));
    }

    for (unsigned i = 0; i < m; i++) {
        for (unsigned j = 0; j < p; j++) {
            C.data[i][j] = 0.0;
            for (unsigned k = 0; k < n; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return C;
}
Matrix matrix_multiply_kij(Matrix A, Matrix B) {
    if (A.columns != B.rows) {
        exit(1);
    }

    unsigned m = A.rows;
    unsigned n = A.columns;
    unsigned p = B.columns;

    Matrix C;
    C.rows = m;
    C.columns = p;

    C.data = (double*)malloc(m sizeof(double));
    for (unsigned i = 0; i < m; i++) {
        C.data[i] = (double)malloc(p * sizeof(double));
        for (unsigned j = 0; j < p; j++) {
            C.data[i][j] = 0.0;
        }
    }

    for (unsigned k = 0; k < n; k++) {
        for (unsigned i = 0; i < m; i++) {
            double r = A.data[i][k];
            for (unsigned j = 0; j < p; j++) {
                C.data[i][j] += r * B.data[k][j];
            }
        }
    }

    return C;
}
Matrix matrix_multiply_jki(Matrix A, Matrix B) {
    if (A.columns != B.rows) {
        exit(1);
    }

    unsigned m = A.rows;
    unsigned n = A.columns;
    unsigned p = B.columns;

    Matrix C;
    C.rows = m;
    C.columns = p;

    C.data = (double*)malloc(m sizeof(double));
    for (unsigned i = 0; i < m; i++) {
        C.data[i] = (double)malloc(p * sizeof(double));
        for (unsigned j = 0; j < p; j++) {
            C.data[i][j] = 0.0;
        }
    }

    for (unsigned j = 0; j < p; j++) {
        for (unsigned k = 0; k < n; k++) {
            double r = B.data[k][j];
            for (unsigned i = 0; i < m; i++) {
                C.data[i][j] += A.data[i][k] * r;
            }
        }
    }

    return C;
}

