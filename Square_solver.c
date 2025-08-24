#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
const double ERROR_RATE = 10e-9;
enum NumberSolutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
};

void test_solve_square();
void check_answers(double coef_a,double coef_b, double coef_c,
                  double correct_root_1, double correct_root_2,
                  int correct_num_roots);

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c);

NumberSolutions solve_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2);
NumberSolutions square_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2);
NumberSolutions linear_equation (double b, double c, double *ptr_root1, double *ptr_root2);

void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2);

bool compare_double(double number1, double number2);

void clear_buffer();

int main()
{
    double coef_a = NAN, coef_b = NAN, coef_c = NAN;
    double root_1 = NAN, root_2 = NAN;
    NumberSolutions nRoots = NO_ROOTS;

    test_solve_square();

    input_coef(&coef_a, &coef_b, &coef_c);

    printf("Now let's move on to finding the roots.\n");

    nRoots = solve_equation(coef_a, coef_b, coef_c, &root_1, &root_2);

    output_results(nRoots, &root_1, &root_2);

    return 0;
}

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c)
{
    assert(ptr_a);
    assert(ptr_b);
    assert(ptr_c);
    assert(ptr_a != ptr_b);
    assert(ptr_a != ptr_c);
    assert(ptr_b != ptr_c);

    printf("Let's solve an equation of the form ax2 + bx + c = 0.\n");

    printf("Enter the coefficient a.\n");
    while (scanf("%lg", ptr_a) != 1)
    {
        printf("Input error!\n");
        clear_buffer();
        printf("Try again!\n");
    }

    printf("Enter the coefficient b.\n");
    while (scanf("%lg", ptr_b) != 1)
    {
        printf("Input error!\n");
        clear_buffer();
        printf("Try again!\n");
    }

    printf("Enter the coefficient c.\n");
    while (scanf("%lg", ptr_c) != 1)
    {
        printf("Input error!\n");
        clear_buffer();
        printf("Try again!\n");
    }
}

NumberSolutions solve_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2)
{
    assert(ptr_root1);
    assert(ptr_root2);
    assert(ptr_root1 != ptr_root2);

    if (compare_double(a, 0))
        return linear_equation(b, c, ptr_root1, ptr_root2);
    else
        return square_equation(a, b, c, ptr_root1, ptr_root2);
}

NumberSolutions linear_equation (double b, double c, double *ptr_root1, double *ptr_root2)
{
    assert(ptr_root1);
    assert(ptr_root2);
    assert(ptr_root1 != ptr_root2);

    if (compare_double(b, 0))
    {
        if (compare_double(c, 0))
            return INFINITE_ROOTS;
        else
            return NO_ROOTS;
    }

    else
    {
        *ptr_root1 = *ptr_root2 = -c/b;
        return ONE_ROOT;
    }
}

NumberSolutions square_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2)
{
    assert(ptr_root1);
    assert(ptr_root2);
    assert(ptr_root1 != ptr_root2);

    double discriminant = NAN;
    discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return NO_ROOTS;

    else if (discriminant > 0)
    {
        *ptr_root1 = (-b + sqrt(discriminant)) / (2 * a);
        *ptr_root2 = (-b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOTS;
    }

    else
    {
        *ptr_root1 = *ptr_root2 = -b / (2 * a);
        return ONE_ROOT;
    }
}

void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2)
{
    assert(ptr_root1);
    assert(ptr_root2);
    assert(ptr_root1 != ptr_root2);

    switch(number_of_roots)
    {
    case NO_ROOTS:
        printf("The equation has no solutions with the given coefficients!");
        break;

    case ONE_ROOT:
        printf("The root of the equation is %lg.\n", *ptr_root1);
        break;

    case TWO_ROOTS:
        printf("The roots of the equation are numbers %lg and %lg.\n", *ptr_root1, *ptr_root2);
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
    if (fabs(number1 - number2) < ERROR_RATE)
        return true;
    else
        return false;
}

void clear_buffer()
{
    int symbol = NAN;
    while ((symbol = getchar()) != 'n' && symbol != EOF)
        return;
}

void test_solve_square()
{
    double correct_root_1 = 2, correct_root_2 = 3;

    int correct_num_roots = 2;

    double coefficient_a = 1;
    double coefficient_b = -5;
    double coefficient_c = 6;

    check_answers(coefficient_a, coefficient_b, coefficient_c,
                  correct_root_1, correct_root_2,
                  correct_num_roots);



}

void check_answers(double coef_a,double coef_b, double coef_c,
                  double correct_root_1, double correct_root_2,
                  int correct_num_roots)
{
    double root_1 = NAN;
    double root_2 = NAN;

    int nRoots = solve_equation(coef_a, coef_b, coef_c, &root_1, &root_2);

    if (!(nRoots == correct_num_roots &&
         (compare_double(correct_root_1, root_1) && compare_double(correct_root_2, root_2)) ||
         (compare_double(correct_root_2, root_1) && compare_double(correct_root_1, root_2))))
        printf("FAIL: Solve_Square(%lg, %lg, %lg, &root_1, &root_2)" //TODO NAN check
               " --> 2, root_1 = %lg, root_2 = %lg (should be root_1 = %lg, root_2 = %lg).\n",
               coef_a, coef_b, coef_c, root_1, root_2, correct_root_1, correct_root_2);
    else
        printf("All good!\n");
}








