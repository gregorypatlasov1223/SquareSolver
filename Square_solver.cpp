#include <TXLib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "Square_solver.h"

int main() //TODO argc argv
{
    coeffs_data coeffs = {};

    roots_data roots = {};

    poltorashka("COMMIT GITHUB!\n");

    user_answer();

    input_coef(&coeffs);

    printf("Now let's move on to finding the roots.\n");

    roots.nRoots = solve_equation(coeffs, &roots);

    output_results(&roots);

    return 0;
}

NumberSolutions solve_equation(coeffs_data coefficiant, roots_data *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));;

    ptr_root -> x1 = NAN;
    ptr_root -> x2 = NAN;

    if (compare_double(coefficiant.a, 0))
        return linear_equation(coefficiant,ptr_root);
    else
        return square_equation(coefficiant,ptr_root);
}

NumberSolutions linear_equation (coeffs_data coefficiant, roots_data *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));

    if (compare_double(coefficiant.b, 0))
    {
        if (compare_double(coefficiant.c, 0))
            return INFINITE_ROOTS;
        else
            return NO_ROOTS;
    }

    else
    {
        ptr_root -> x1 = -coefficiant.c / coefficiant.b;
        ptr_root -> x2 = -coefficiant.c / coefficiant.b;

        if (compare_double(0, ptr_root -> x1))
            ptr_root -> x1 = 0;
        if (compare_double(0, ptr_root -> x2))
            ptr_root -> x2 = 0;

        return ONE_ROOT;
    }
}

NumberSolutions square_equation(coeffs_data coefficiant, roots_data *ptr_root)  //&(*ptr_root).x1    &(ptr_root->x1)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));

    double discriminant = NAN;

    discriminant = coefficiant.b * coefficiant.b - 4 * coefficiant.a * coefficiant.c;

    if (discriminant < 0)
        return NO_ROOTS;

    else if (discriminant > 0)
    {
        ptr_root -> x1 = (-coefficiant.b + sqrt(discriminant)) / (2 * coefficiant.a);
        ptr_root -> x2 = (-coefficiant.b - sqrt(discriminant)) / (2 * coefficiant.a);

        if (compare_double(0, ptr_root -> x1))
            ptr_root -> x1 = 0;
        if (compare_double(0, ptr_root -> x2))
            ptr_root -> x2 = 0;

        return TWO_ROOTS;
    }

    else
    {
        ptr_root -> x1 = -coefficiant.b / (2 * coefficiant.a);
        ptr_root -> x2 = -coefficiant.b / (2 * coefficiant.a);

        if (compare_double(0, ptr_root -> x1))
            ptr_root -> x1 = 0;
        if (compare_double(0, ptr_root -> x2))
            ptr_root -> x2 = 0;

        return ONE_ROOT;
    }
}

void output_results(roots_data *solutions)
{
    switch(solutions->nRoots)
    {
    case NO_ROOTS:
        printf("The equation has no solutions with the given coefficients!");
        break;

    case ONE_ROOT:
        printf("The root of the equation is %lg.\n", solutions->x1);
        break;

    case TWO_ROOTS:
        printf("The roots of the equation are numbers %lg and %lg.\n", solutions->x1, solutions->x2);
        break;

    case INFINITE_ROOTS:
        printf("An infinite number of solutions.");
        break;

    default :
        printf("Interesting choice!");
    }
}

bool compare_double(double number1, double number2)
{
    if (isnan(number1) && isnan(number2))
        return true;

    if ((isnan(number1) && !isnan(number2)) || (!isnan(number1) && isnan(number2)))
        return false;

    return fabs(number1 - number2) < ERROR_RATE;
}

void clear_buffer()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n' && symbol != EOF) {}
}


int one_test(coeffs_data test_coeffs, roots_data *expected_roots)
{
    roots_data calculated_roots = {};

    calculated_roots.nRoots = solve_equation(test_coeffs, &calculated_roots);

    sort_two_values(&expected_roots->x1, &expected_roots->x2);
    sort_two_values(&calculated_roots.x1, &calculated_roots.x2);

    if (!(calculated_roots.nRoots == expected_roots->nRoots &&
         (compare_double(expected_roots->x1, calculated_roots.x1) && compare_double(expected_roots->x2, calculated_roots.x2))))
    {
        show_error (test_coeffs, calculated_roots, *expected_roots);

        return 0;
    }

    else
        return 1;
}

void user_answer()
{
    int symbols_number = 0;
    int passed = 0;
    int total_tests = 0;

    run_tests_from_file(&passed, &total_tests);

    printf("If you want to see the results of unit tests write 'YES'\n"
           "If you don't want to see the results of unit tests write 'NO'\n");

    scanf("%*s%n", &symbols_number);

    if (symbols_number == 3)
        printf("\nResults: %d from %d tests completed\n", passed, total_tests);
    else
        printf("Alright, let's move on to solving the equation.\n");
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

void poltorashka(const char *name)
 {
    printf(" ");
    printf(" \n");
    printf("       ....／＞　 フ.....\n　　　　　| 　_　 _|\n　 　　　／`ミ _* 彡 -- %s!!\n　　 　 /　　　 　 |\n　　　 /　 ヽ　　 ﾉ\n　／￣|　　 |　|　|\n　| (￣ヽ＿_ヽ_)_)\n　＼二つ\n" ,name);
    printf(" ");
}

void run_tests_from_file(int *passed, int *total_tests)
{
    FILE *file = fopen("test.txt", "r"); //TODO in func
    if (file == NULL)
    {
        printf("File test.txt isn't open\n");
        return;
    }

    int change_for_nRoots = 0;

    while (!feof(file))
    {
        coeffs_data coeffs = {};
        roots_data roots = {};

        int num_of_symbols = fscanf(file, "%lg %lg %lg %lg %lg %d",
                              &coeffs.a, &coeffs.b, &coeffs.c,
                              &roots.x1, &roots.x2, &change_for_nRoots); //TODO fscanf return value
        roots.nRoots = (NumberSolutions)change_for_nRoots; //TODO func - what if we (NumberSolutions) 100

        if (num_of_symbols != 6)
            break;

        *total_tests = *total_tests + 1;
        *passed += one_test(coeffs, &roots); //TODO split on files -> test.cpp test.h || input.cpp main.cpp solver.cpp
    }
    fclose(file);
     //TODO escape - sequences
}

void show_error (coeffs_data test_coeffs, roots_data calculated_roots, roots_data expected_roots)
{
    printf("FAIL: Solve_Square(%lg, %lg, %lg,"
               " --> %d, calculated_roots.x1 = %lg, calculated_roots.x2 = %lg"
               " (should be expected_roots->x1 = %lg, expected_roots->x2 = %lg).\n",
               test_coeffs.a, test_coeffs.b, test_coeffs.c,
               calculated_roots.nRoots, calculated_roots.x1, calculated_roots.x2,
               expected_roots.x1, expected_roots.x2);
}





