#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "square_solver.h"
#include "test.h"

NumberSolutions solve_equation(coeffs_data coefficiant, roots_data *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));;

    ptr_root->x1 = NAN;
    ptr_root->x2 = NAN;

    if (compare_double(coefficiant.a, 0))
        return linear_equation(coefficiant,ptr_root);
    else
        return square_equation(coefficiant,ptr_root);
}

NumberSolutions linear_equation(coeffs_data coefficiant, roots_data *ptr_root)
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
        ptr_root->x1 = -coefficiant.c / coefficiant.b;
        ptr_root->x2 = -coefficiant.c / coefficiant.b;

        if (compare_double(0, ptr_root->x1))
            ptr_root->x1 = 0;
        if (compare_double(0, ptr_root->x2))
            ptr_root->x2 = 0;

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
        ptr_root->x1 = (-coefficiant.b + sqrt(discriminant)) / (2 * coefficiant.a);
        ptr_root->x2 = (-coefficiant.b - sqrt(discriminant)) / (2 * coefficiant.a);

        if (compare_double(0, ptr_root->x1))
            ptr_root->x1 = 0;
        if (compare_double(0, ptr_root->x2))
            ptr_root->x2 = 0;

        return TWO_ROOTS;
    }

    else
    {
        ptr_root->x1 = -coefficiant.b / (2 * coefficiant.a);
        ptr_root->x2 = -coefficiant.b / (2 * coefficiant.a);

        if (compare_double(0, ptr_root->x1))
            ptr_root->x1 = 0;
        if (compare_double(0, ptr_root->x2))
            ptr_root->x2 = 0;

        return ONE_ROOT;
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

void user_answer()
{
    int passed = 0;
    int total_tests = 0;

    run_tests_from_file(&passed, &total_tests);
}







