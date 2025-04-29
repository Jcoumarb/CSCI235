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

	C.data = (double**)malloc(m * sizeof(double*));

	for (unsigned i = 0; i < m; i++) {
        	C.data[i] = (double*)malloc(p * sizeof(double));
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

