#ifndef TEST_H_
#define TEST_H_

int one_test(coeffs_data test_coeffs, roots_data *expected_roots);
void run_tests_from_file(int *passed, int *total_tests);
void show_error(coeffs_data test_coeffs, roots_data calculated_roots, roots_data expected_roots);
void sort_two_values(double *number1, double *number2);
FILE* open_file_and_check(const char* filename, const char* mode);

#endif  // TEST_H_
