#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int mmult(double *c,
          double *a, int aRows, int aCols,
          double *b, int bRows, int bCols) {
  int i, j, k;
  for (i = 0; i < aRows; i++) {
    for (j = 0; j < bCols; j++) {
      c[i*bCols + j] = 0;
    }
    for (k = 0; k < aCols; k++) {
      for (j = 0; j < bCols; j++) {
        c[i*bCols + j] += a[i*aCols + k] * b[k*bCols + j];
      }
    }
  }
  return 0;
}

double* gen_matrix(int n, int m) {
  int i, j;
  double *a = malloc(sizeof(double) * n * m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      a[i*m + j] = (double)rand()/RAND_MAX;
    }
  }
  return a;
}

void compare_matrices(double* a, double* b, int nRows, int nCols) {
        int n = nRows * nCols;
        int i, j, k;
        for (k = 0; k < n; ++k) {
                if (fabs(a[k]-b[k])/fabs(a[k]) > 1e-12) {
                        i = k/nCols;
                        j = k%nCols;
                        printf("a[%d][%d] == %.12g\nb[%d][%d] == %.12g\ndelta == %.12g\nrelerr$
                                i, j, a[k], i, j, b[k], fabs(a[k]-b[k]), fabs(a[k]-b[k])/fabs($
                        return;
                }
        }
        printf("Matrices are the same\n");
}
