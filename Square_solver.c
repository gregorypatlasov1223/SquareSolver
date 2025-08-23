#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum number_of_solutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITE_ROOTS = -1
};

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c);

int solver_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2);
int square_equaption(double a, double b, double c, double *ptr_root1, double *ptr_root2);
int linear_equation (double a, double b, double c, double *ptr_root1, double *ptr_root2);

void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2);

bool inaccuracy_decection(double number1, double number2, double value);

void clear_buffer();

int main()
{
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double root_1 = 0, root_2 = 0;
    int nRoots = 0;

    input_coef(&coef_a, &coef_b, &coef_c);

    printf("Now let's move on to finding the roots.\n");

    nRoots = solver_equation(coef_a, coef_b, coef_c, &root_1, &root_2);

    output_results(nRoots, &root_1, &root_2);

    return 0;
}

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c)
{
    printf("Let's solve an equation of the form ax2 + bx + c = 0.\n");

    printf("Enter the coefficient a.\n");
    while (scanf("%lf", ptr_a) != 1)
    {
        printf("Input error!\n");
        clear_buffer();
        printf("Try again!\n");
    }

    printf("Enter the coefficient b.\n");
    while (scanf("%lf", ptr_b) != 1)
    {
        printf("Input error!\n");
        clear_buffer();
        printf("Try again!\n");
    }

    printf("Enter the coefficient c.\n");
    while (scanf("%lf", ptr_c) != 1)
    {
        printf("Input error!\n");
        clear_buffer();
        printf("Try again!\n");
    }
}

int solver_equation(double a, double b, double c, double *ptr_root1, double *ptr_root2)
{
    if (a == 0)
        linear_equation(a, b, c, ptr_root1, ptr_root2);
    else
        square_equaption(a, b, c, ptr_root1, ptr_root2);
}

void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2)
{
    if (number_of_roots == NO_ROOTS)
        printf("The equation has no solutions with the given coefficients!");

    if (number_of_roots == ONE_ROOT)
        printf("The root of the equation is %lf.\n", *ptr_root1);

    if (number_of_roots == TWO_ROOTS)
        printf("The roots of the equation are numbers %lf and %lf.\n", *ptr_root1, *ptr_root2);

    if (number_of_roots == INFINITE_ROOTS)
        printf("An infinite number of solutions.");
}

bool inaccuracy_decection(double number1, double number2, double value)
{
    const double ERROR_RATE = 0.00000001;
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

int linear_equation (double a, double b, double c, double *ptr_root1, double *ptr_root2)
{
    const double ERROR_RATE = 0.00000001;
    const double ZERO = 0;
    if (inaccuracy_decection(a, ZERO, ERROR_RATE))
    {
        if (inaccuracy_decection(b, ZERO, ERROR_RATE))
        {
            if (inaccuracy_decection(c, ZERO, ERROR_RATE))
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
}

int square_equaption(double a, double b, double c, double *ptr_root1, double *ptr_root2)
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





