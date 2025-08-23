#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const double ERROR_RATE = 10e-9;
const double ZERO = 0;
enum NumberSolutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
};

void test_solve_square();

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c);

NumberSolutions solve_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2);
NumberSolutions square_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2);
NumberSolutions linear_equation (double b, double c, double *ptr_root1, double *ptr_root2);

void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2);

bool compare_double(double number1, double number2);

void clear_buffer();

int main()
{
    double  coef_a = 0, coef_b = 0, coef_c = 0;
    double root_1 = 0, root_2 = 0;
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
    if (compare_double(a, ZERO))
        return linear_equation(b, c, ptr_root1, ptr_root2);
    else
        return square_equation(a, b, c, ptr_root1, ptr_root2);
}

NumberSolutions linear_equation (double b, double c, double *ptr_root1, double *ptr_root2)
{
        if (compare_double(b, ZERO))
        {
            if (compare_double(c, ZERO))
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
    double discriminant = 0;
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
    int symbol = 0;
    while ((symbol = getchar()) != 'n' && symbol != EOF)
        return;
}

void test_solve_square()
{
    double root_1 = NAN, root_2 = NAN; // TODO: NAN NAN != NAN
    int nRoots = solve_equation(1, -5, 6, &root_1, &root_2);

    if (!(nRoots == 2 && (compare_double(2, root_1) && compare_double(3, root_2)) || (compare_double(3, root_1) && compare_double(2, root_2))))
        printf("FAIL: Solve_Square(1, -5, 6, &root_1, &root_2)"
                " --> 2, root_1 = %lg, root_2 = %lg (should be root_1 = 2, root_2 = 3).\n", root_1, root_2);
    else
        printf("All good!\n");

}








