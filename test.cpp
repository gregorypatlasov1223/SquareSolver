#include <TXLib.h>
#include <stdio.h>
#include "square_solver.h"
#include "colors_codes.h"

bool one_test(coeffs_data test_coeffs, roots_data *expected_roots)
{
    roots_data calculated_roots = {};

    calculated_roots.nRoots = solve_equation(test_coeffs, &calculated_roots);

    sort_two_values(&expected_roots->x1, &expected_roots->x2);
    sort_two_values(&calculated_roots.x1, &calculated_roots.x2);

    if (!(calculated_roots.nRoots == expected_roots->nRoots &&
         (compare_double(expected_roots->x1, calculated_roots.x1) && compare_double(expected_roots->x2, calculated_roots.x2))))
    {
        show_error(test_coeffs, calculated_roots, *expected_roots);

        return false;
    }

    else
        return true;
}

void run_tests_from_file(int *passed, int *total_tests)
{
    FILE* file = open_file_and_check("test.txt", "r");

    if (file == NULL)
        return;

    int change_for_nRoots = 0;

    while (!feof(file))
    {
        coeffs_data coeffs = {};
        roots_data roots   = {};

        int num_of_symbols = fscanf(file, "%lg %lg %lg %lg %lg %d",
                              &coeffs.a, &coeffs.b, &coeffs.c,
                              &roots.x1, &roots.x2, &change_for_nRoots);

        roots.nRoots = (NumberSolutions)change_for_nRoots;

        if (num_of_symbols != 6)
            break;

        *total_tests = *total_tests + 1;
        *passed += one_test(coeffs, &roots);
    }

    fclose(file);
}

void show_error(coeffs_data test_coeffs, roots_data calculated_roots, roots_data expected_roots) //TODO
{
    printf(RED "FAIL: Solve_Square(%lg, %lg, %lg,"
               " --> %d, calculated_roots.x1 = %lg, calculated_roots.x2 = %lg"
               " (should be expected_roots->x1 = %lg, expected_roots->x2 = %lg).\n" RESET,
               test_coeffs.a, test_coeffs.b, test_coeffs.c,
               calculated_roots.nRoots, calculated_roots.x1, calculated_roots.x2,
               expected_roots.x1, expected_roots.x2);
}

void sort_two_values(double *number1, double *number2)
{
    if (!isnan(*number1) && !isnan(*number2))
    {
        if (*number1 < *number2)
        {
            double temp = *number1;
            *number1 = *number2;
            *number2 = temp;
        }
    }
}


FILE* open_file_and_check(const char* filename, const char* mode)
{
    FILE* file = fopen(filename, mode);

    if (file == NULL)
    {
        printf(RED "File %s isn't open\n" RESET, filename);
        return NULL;
    }

    else
        return file;
}
