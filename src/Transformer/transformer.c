#include "transformer.h"

void s21_translate(float *M, float x, float y, float z) {
  float A[SIZE_M * SIZE_M] = {M[0],  M[1],  M[2],  M[3], M[4],  M[5],
                              M[6],  M[7],  M[8],  M[9], M[10], M[11],
                              M[12], M[13], M[14], M[15]};

  float B[SIZE_M * SIZE_M] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, z, 1};
  mult_matrix(M, A, B);
}
void s21_rotate(float *M, float angle, float x, float y,
                float z) { // реализована упрощенная версия (вращение только
                           // вокруг осей X, Y, Z)

  angle = angle / 360.0 * 2 * PI;

  float A[SIZE_M * SIZE_M] = {M[0],  M[1],  M[2],  M[3], M[4],  M[5],
                              M[6],  M[7],  M[8],  M[9], M[10], M[11],
                              M[12], M[13], M[14], M[15]};

  if (fabsf(x - 1) < EPS) { // вращение по оси X

    float B[SIZE_M * SIZE_M] = {
        1, 0,           0,          0, 0, cos(angle), sin(angle), 0,
        0, -sin(angle), cos(angle), 0, 0, 0,          0,          1};

    mult_matrix(M, A, B);
  } else if (fabsf(y - 1) < EPS) { // вращение по оси Y

    float B[SIZE_M * SIZE_M] = {cos(angle), 0, -sin(angle), 0, 0, 1, 0, 0,
                                sin(angle), 0, cos(angle),  0, 0, 0, 0, 1};

    mult_matrix(M, A, B);
  } else if (fabsf(z - 1) < EPS) { // вращение по оси Z

    float B[SIZE_M * SIZE_M] = {
        cos(angle), sin(angle), 0, 0, -sin(angle), cos(angle), 0, 0,
        0,          0,          1, 0, 0,           0,          0, 1};

    mult_matrix(M, A, B);
  }
}
void s21_scale(float *M, float x, float y, float z) {
  float A[SIZE_M * SIZE_M] = {M[0],  M[1],  M[2],  M[3], M[4],  M[5],
                              M[6],  M[7],  M[8],  M[9], M[10], M[11],
                              M[12], M[13], M[14], M[15]};
  float B[SIZE_M * SIZE_M] = {x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1};
  mult_matrix(M, A, B);
}

void mult_matrix(float *M, float *A, float *B) {
  for (int i = 0; i < SIZE_M; i++) {
    for (int j = 0; j < SIZE_M; j++) {
      M[SIZE_M * j + i] = 0;
      for (int r = 0; r < SIZE_M; r++) {
        M[SIZE_M * j + i] += A[i + SIZE_M * r] * B[r + SIZE_M * j];
      }
    }
  }
}
