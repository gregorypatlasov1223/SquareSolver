#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "square_solver.h"
#include "test.h"

NumberSolutions solve_equation(coeffs_data coefficient, roots_data *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));;

    ptr_root->x1 = NAN;
    ptr_root->x2 = NAN;

    if (compare_double(coefficient.a, 0))
        return linear_equation(coefficient,ptr_root);
    else
        return square_equation(coefficient,ptr_root);
}

NumberSolutions linear_equation(coeffs_data coefficient, roots_data *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));

    if (compare_double(coefficient.b, 0))
    {
        if (compare_double(coefficient.c, 0))
            return INFINITE_ROOTS;
        else
            return NO_ROOTS;
    }

    else
    {
        ptr_root->x1 = -coefficient.c / coefficient.b;
        ptr_root->x2 = -coefficient.c / coefficient.b;

        if (compare_double(0, ptr_root->x1))
            ptr_root->x1 = 0;
        if (compare_double(0, ptr_root->x2))
            ptr_root->x2 = 0;

        return ONE_ROOT;
    }
}

NumberSolutions square_equation(coeffs_data coefficient, roots_data *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));

    double discriminant = NAN;

    discriminant = coefficient.b * coefficient.b - 4 * coefficient.a * coefficient.c;

    if (discriminant < 0)
        return NO_ROOTS;

    else if (discriminant > 0)
    {
        ptr_root->x1 = (-coefficient.b + sqrt(discriminant)) / (2 * coefficient.a);
        ptr_root->x2 = (-coefficient.b - sqrt(discriminant)) / (2 * coefficient.a);

        if (compare_double(0, ptr_root->x1))
            ptr_root->x1 = 0;
        if (compare_double(0, ptr_root->x2))
            ptr_root->x2 = 0;

        return TWO_ROOTS;
    }

    else
    {
        ptr_root->x1 = -coefficient.b / (2 * coefficient.a);
        ptr_root->x2 = -coefficient.b / (2 * coefficient.a);

        if (compare_double(0, ptr_root->x1))
            ptr_root->x1 = 0;
        if (compare_double(0, ptr_root->x2))
            ptr_root->x2 = 0;

        return ONE_ROOT;
    }
}

bool compare_double(double number1, double number2)
{
    if (isnan(number1) && isnan(number2)) //TODO: isinf
        return true;

    if ((isnan(number1) && !isnan(number2)) || (!isnan(number1) && isnan(number2)))
        return false;

    return fabs(number1 - number2) < ERROR_RATE;
}

void user_answer() //TODO: Remove or change
{
    //TODO: make local
    int passed = 0;
    int total_tests = 0;

    run_tests_from_file(&passed, &total_tests);
}







