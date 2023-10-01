#ifndef TESTER_H
#define TESTER_H

#include "../Parser/parser.h"
#include "../Transformer/transformer.h"
#include <check.h>

Suite *get_suite_parser();
Suite *get_suite_transformer();

int eq_matrix(float *A, float *B);
int eq_object(object obj1, object obj2);

#endif // TESTER_H
