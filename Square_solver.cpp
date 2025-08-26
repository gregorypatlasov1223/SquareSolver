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

    roots_data results = {};

    poltorashka("COMMIT GITHUB!\n");

    user_wishes();

    run_tests_from_file();

    input_coef(&coeffs);

    printf("Now let's move on to finding the roots.\n");

    roots.nRoots = solve_equation(coeffs, &roots);

    if (compare_double(0, roots.x1)) //TODO in solve_equation
        roots.x1 = 0;
    if (compare_double(0, roots.x2))
        roots.x2 = 0;

    output_results(&results);

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
        return TWO_ROOTS;
    }

    else
    {
        ptr_root -> x1 = -coefficiant.b / (2 * coefficiant.a);
        ptr_root -> x2 = -coefficiant.b / (2 * coefficiant.a);
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

    //assert(isnan(number1) && isnan(number2));
    if ((isnan(number1) && !isnan(number2)) || (!isnan(number1) && isnan(number2)))
        return false;

    return fabs(number1 - number2) < ERROR_RATE;
}

void clear_buffer()
{
    int symbol = NAN;
    while ((symbol = getchar()) != 'n' && symbol != EOF) ;
}


int one_test(coeffs_data t_coeffs, roots_data *expected_roots) //TODO rename
{
    roots_data calculated_roots; //TODO initialize

    calculated_roots.nRoots = solve_equation(t_coeffs, &calculated_roots);

    sort_two_values(&expected_roots->x1, &expected_roots->x2);
    sort_two_values(&calculated_roots.x1, &calculated_roots.x2);

    if (!(calculated_roots.nRoots == expected_roots->nRoots &&
         (compare_double(expected_roots->x1, calculated_roots.x1) && compare_double(expected_roots->x2, calculated_roots.x2))))
    {
        printf("FAIL: Solve_Square(%lg, %lg, %lg," //TODO NAN check
               " --> %d, calculated_roots.x1 = %lg, calculated_roots.x2 = %lg"
               " (should be expected_roots->x1 = %lg, expected_roots->x2 = %lg).\n",
               t_coeffs.a, t_coeffs.b, t_coeffs.c,
               calculated_roots.nRoots, calculated_roots.x1, calculated_roots.x2,
               expected_roots->x1, expected_roots->x2); //TODO use func

        return 0; //TODO bool
    }

    else
        return 1;
}

int run_test()
{
    int passed = 0; //TODO rename

    coeffs_data t_coeffs[] = {  {1, -5, 6}       , {0, 3, 6}         , {0, 0, 1}           , {0, 0, 0}                  };
    roots_data t_roots[]   = {  {2, 3, TWO_ROOTS}, {-2, -2, ONE_ROOT}, {NAN, NAN, NO_ROOTS}, {NAN, NAN, INFINITE_ROOTS} };

    size_t size = sizeof(t_coeffs) / sizeof(t_coeffs[0]);

    for (size_t i = 0; i < size; i++)
    {
        one_test(t_coeffs[i], &t_roots[i]);
        passed += one_test(t_coeffs[i], &t_roots[i]);
    }

    return passed;
}

void user_wishes() //TODO rename
{
    int symbols_number = 0;
    int passed = 0;

    passed = run_test();

    printf("If you want to see the results of unit tests write 'YES'\n"
           "If you don't want to see the results of unit tests write 'NO'\n"); //TODO use one printf

    scanf("%*s%n", &symbols_number);

    if (symbols_number == 3)
        printf("passed tests = %d\n", passed);
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
    printf(" \n");
    printf(" ");
}

void run_tests_from_file()
{
    FILE *file = fopen("test.txt", "r"); //TODO in func
    if (file == NULL)
    {
        printf("File test.txt isn't open\n");
        return;
    }

    int change_for_nRoots = 0;
    int passed = 0;
    int total_tests = 0;

    while (!feof(file))
    {
        coeffs_data coeffs;
        roots_data roots; //TODO initialize

        int num_of_symbols = fscanf(file, "%lg %lg %lg %lg %lg %d",
                              &coeffs.a, &coeffs.b, &coeffs.c,
                              &roots.x1, &roots.x2, &change_for_nRoots); //TODO fscanf return value
        roots.nRoots = (NumberSolutions)change_for_nRoots; //TODO func - what if we (NumberSolutions) 100

        if (num_of_symbols != 6)
            break;

        total_tests++;
        passed += one_test(coeffs, &roots); //TODO split on files -> test.cpp test.h || input.cpp main.cpp solver.cpp
    }
    fclose(file);
    printf("\nResults: %d from %d tests completed\n", passed, total_tests); //TODO escape - sequences
}





