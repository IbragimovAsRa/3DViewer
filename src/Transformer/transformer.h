#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <math.h>
#include <stdio.h>

#define SIZE_M 4
#define EPS 1e-3
#define PI 3.14159265358979323846
#ifdef __cplusplus
extern "C" {
#endif

/* Доработать:
- Проверка на некоректный ввод
*/
void s21_translate(float *M, float x, float y, float z);
void s21_rotate(float *M, float angle, float x, float y, float z);
void s21_scale(float *M, float x, float y, float z);

void mult_matrix(float *M, float *A, float *B);
#ifdef __cplusplus
}
#endif

#endif // TRANSFORMER_H
