#include "tester.h"

#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define WHITE "\x1B[0m"

void test_func(Suite *s);

int main(void) {
  test_func(get_suite_transformer());
  test_func(get_suite_parser());

  return 0;
}

void test_func(Suite *s) {
  int failed = 0;
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  if (failed == 0)
    printf(GREEN "Success\n" WHITE);
  else
    printf(RED "Failed\n" WHITE);
}
