#include "tester.h"

// Test TRANSFORMER
// - translate
START_TEST(test_1) {
  float A[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  float x = 0;
  float y = 0;
  float z = -10;
  float B[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, -10, 1};

  s21_translate(A, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

START_TEST(test_2) {
  float A[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  float x = 0;
  float y = -10;
  float z = 0;
  float B[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -10, 0, 1};

  s21_translate(A, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

START_TEST(test_3) {
  float A[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  float x = -10;
  float y = 0;
  float z = 0;
  float B[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -10, 0, 0, 1};

  s21_translate(A, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

START_TEST(test_4) {
  float A[16] = {2, 7, 3, 17, 2, 9, 12, 11, 7, 4, 16, 5, 2, 3, 11, 9};
  float x = -10;
  float y = 20;
  float z = 15;
  float B[16] = {2, 7, 3, 17, 2, 9, 12, 11, 7, 4, 16, 5, 127, 173, 461, 134};

  s21_translate(A, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

// - scale
START_TEST(test_5) {
  float A[16] = {2, 7, 3, 17, 2, 9, 12, 11, 7, 4, 16, 5, 2, 3, 11, 9};
  float x = -10;
  float y = 20;
  float z = 15;
  float B[16] = {-20, -70, -30, -170, 40, 180, 240, 220,
                 105, 60,  240, 75,   2,  3,   11,  9};
  s21_scale(A, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

// - rotate

START_TEST(test_6) {
  float A[16] = {2, 7, 3, 17, 2, 9, 12, 11, 7, 4, 16, 5, 2, 3, 11, 9};

  float angle = 1.2;
  float x = 0;
  float y = 0;
  float z = 1; // вращение вокруг оси Z
  angle = angle * 360.0 / 2.0 / PI;
  float B[16] = {2.588774,  10.924769, 12.271431, 16.412399,
                 -1.139346, -3.262997, 1.552194,  -11.858583,
                 7,         4,         16,        5,
                 2,         3,         11,        9};
  s21_rotate(A, angle, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

START_TEST(test_7) {
  float A[16] = {2, 7, 3, 17, 2, 9, 12, 11, 7, 4, 16, 5, 2, 3, 11, 9};

  float angle = 1.2;
  float x = 0;
  float y = 1; // вращение вокруг оси Y
  float z = 0;
  angle = angle * 360.0 / 2.0 / PI;
  float B[16] = {-5.799496, -1.191621, -13.825409, 1.499919,  2, 9, 12, 11,
                 4.400559,  7.973638,  8.593802,   17.656295, 2, 3, 11, 9};
  s21_rotate(A, angle, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

START_TEST(test_8) {
  float A[16] = {2, 7, 3, 17, 2, 9, 12, 11, 7, 4, 16, 5, 2, 3, 11, 9};

  float angle = 1.2;
  float x = 1; // вращение вокруг оси X
  float y = 0;
  float z = 0;
  angle = angle * 360.0 / 2.0 / PI;
  float B[16] = {2,         7,        3,        17,        7.248924,  6.989333,
                 19.260764, 8.646077, 0.672439, -6.938842, -5.386648, -8.440545,
                 2,         3,        11,       9};
  s21_rotate(A, angle, x, y, z);
  ck_assert_int_eq(eq_matrix(A, B), 1);
}
END_TEST

START_TEST(test_9) {

  vertex ver[3];

  ver[0].x = 1;
  ver[0].y = -1;
  ver[0].z = -1;

  ver[1].x = 1;
  ver[1].y = -1;
  ver[1].z = 1;

  ver[2].x = -1;
  ver[2].y = -1;
  ver[2].z = 1;

  polygon pol[2];

  pol[0].amount_f = 3;
  pol[1].amount_f = 3;

  int f1[3] = {1, 2, 3};
  int f2[3] = {2, 3, 1};

  pol[0].f = f1;
  pol[1].f = f2;

  object obj1;
  obj1.amount_v = 3;
  obj1.amount_p = 2;
  obj1.v = ver;
  obj1.p = pol;

  object obj2 = parser("test_cub.obj");

  ck_assert_int_eq(eq_object(obj2, obj1), 1);
  free_object(&obj2);
}
END_TEST

// Test PARSER

Suite *get_suite_transformer() {
  Suite *s = suite_create("transformer suite");
  TCase *tc = tcase_create("transformer cases");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);

  return s;
}

Suite *get_suite_parser() {
  Suite *s = suite_create("parser suite");
  TCase *tc = tcase_create("parser cases");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_9);

  return s;
}
int eq_object(object obj1, object obj2) {
  int result = 1;

  // проверка вершин
  if (obj1.amount_v == obj2.amount_v) {
    for (int i = 0; i < obj1.amount_v; i++) {
      if ((fabsl(obj1.v[i].x - obj2.v[i].x) > EPS) ||
          (fabsl(obj1.v[i].y - obj2.v[i].y) > EPS) ||
          (fabsl(obj1.v[i].z - obj2.v[i].z) > EPS)) {
        result = 0;
        break;
      }
    }
  } else {
    result = 0;
  }

  // проверка полигонов
  if (result != 0 && obj1.amount_p == obj2.amount_p) {
    for (int i = 0; i < obj1.amount_p; i++) {
      if (obj1.p[i].amount_f == obj2.p[i].amount_f) {
        for (int j = 0; j < obj1.p[i].amount_f; j++) {
          if (obj1.p[i].f[j] != obj2.p[i].f[j]) {
            result = 0;
            break;
          }
        }
      } else {
        result = 0;
        break;
      }
    }
  } else {
    result = 0;
  }

  return result;
}
int eq_matrix(float *A, float *B) {
  int result = 1;
  for (int i = 0; i < 16; i++) {
    if (fabsf(A[i] - B[i]) > EPS) {
      result = 0;
    }
  }
  return result;
}
