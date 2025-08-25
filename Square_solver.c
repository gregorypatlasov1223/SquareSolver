#include <TXLib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>


enum NumberSolutions
{
    NO_ROOTS       = 0,
    ONE_ROOT       = 1,
    TWO_ROOTS      = 2,
    INFINITE_ROOTS = -1
};

struct coeffs
{
    double a;
    double b;
    double c;
};

struct roots
{
    double x1;
    double x2;
    NumberSolutions nRoots;
};

const double ERROR_RATE = 10e-15;

void user_wishes();

void run_test();

int one_test(coeffs t_coeffs_1, roots expexted_roots);

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c);

void error_output();

NumberSolutions solve_equation  (coeffs coefficiant, roots *ptr_root);
NumberSolutions square_equation (coeffs coefficiant, roots *ptr_root);
NumberSolutions linear_equation (coeffs coefficiant, roots *ptr_root);

void output_results(int number_of_roots, double root1, double root2);

bool compare_double(double number1, double number2);

void sort_two_values(double *x1, double *x2);

void clear_buffer();

int main()
{
    coeffs coeffs_1 = {};

    roots roots_1 = {};

    user_wishes();

    input_coef(&coeffs_1.a, &coeffs_1.b, &coeffs_1.c);

    printf("Now let's move on to finding the roots.\n");

    roots_1.nRoots = solve_equation(coeffs_1, &roots_1);

    if (compare_double(0, roots_1.x1))
        roots_1.x1 = 0;
    if (compare_double(0, roots_1.x2))
        roots_1.x2 = 0;

    output_results(roots_1.nRoots, roots_1.x1, roots_1.x2);

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
        error_output();

    printf("Enter the coefficient b.\n");
    while (scanf("%lg", ptr_b) != 1)
        error_output();

    printf("Enter the coefficient c.\n");
    while (scanf("%lg", ptr_c) != 1)
        error_output();
}

NumberSolutions solve_equation(coeffs coefficiant, roots *ptr_root)
{
    assert(&(ptr_root->x1));
    assert(&(ptr_root->x2));
    assert(&(ptr_root->x1) != &(ptr_root->x2));;

    if (compare_double(coefficiant.a, 0))
        return linear_equation(coefficiant,ptr_root);
    else
        return square_equation(coefficiant,ptr_root);
}

NumberSolutions linear_equation (coeffs coefficiant, roots *ptr_root)
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

NumberSolutions square_equation(coeffs coefficiant, roots *ptr_root)  //&(*ptr_root).x1    &(ptr_root->x1)
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

void output_results(int number_of_roots, double root1, double root2)
{
    assert(!isnan(root1));
    assert(!isnan(root2));

    switch(number_of_roots)
    {
    case NO_ROOTS:
        printf("The equation has no solutions with the given coefficients!");
        break;

    case ONE_ROOT:
        printf("The root of the equation is %lg.\n", root1);
        break;

    case TWO_ROOTS:
        printf("The roots of the equation are numbers %lg and %lg.\n", root1, root2);
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
    int symbol = NAN;
    while ((symbol = getchar()) != 'n' && symbol != EOF) ;
}


int one_test(coeffs t_coeffs_1, roots expexted_roots)
{
    expexted_roots.x1 = NAN;
    expexted_roots.x2 = NAN;

    roots calculated_roots;

    calculated_roots.nRoots = solve_equation(t_coeffs_1, &calculated_roots);

    sort_two_values(&expexted_roots.x1, &expexted_roots.x2);
    sort_two_values(&calculated_roots.x1, &calculated_roots.x2);

    if (!(calculated_roots.nRoots == expexted_roots.nRoots &&
         (compare_double(expexted_roots.x1, calculated_roots.x2) && compare_double(expexted_roots.x2, calculated_roots.x2))))
    {
        printf("FAIL: Solve_Square(%lg, %lg, %lg," //TODO NAN check
               " --> %d, calculated_roots.x1 = %lg, calculated_roots.x2 = %lg"
               " (should be expexted_roots.x1 = %lg, expexted_roots.x2 = %lg).\n",
               t_coeffs_1.a, t_coeffs_1.b, t_coeffs_1.c,
               calculated_roots.nRoots, calculated_roots.x1, calculated_roots.x2,
               expexted_roots.x1, expexted_roots.x2);
        return 0;
    }

    else
        return 1;
}


void run_test()
{

    coeffs t_coeffs_1[] = {     {1, -5, 6}        , {0, 3, 6},         {0, 0, 1},              {0, 0, 0}, };
    roots t_roots_1[] = {  {2, 3, TWO_ROOTS}, {-2, -2, ONE_ROOT}, {NAN, NAN, NO_ROOTS}, {NAN, NAN, INFINITE_ROOTS} };

    size_t size = sizeof(t_coeffs_1) / sizeof(t_coeffs_1[0]);

    for (size_t i = 0; i < size; i++)
        one_test(t_coeffs_1[i], t_roots_1[i]);
}


void error_output()
{
    printf("Input error!\n");
    clear_buffer();
    printf("Try again!\n");
}

void user_wishes()
{
    int symbols_number = 0;
    int num_errors = 0;

    run_test();

    printf("If you want to see the results of unit tests write 'YES'\n");
    printf("If you don't want to see the results of unit testss write 'NO'\n");

    scanf("%*s%n", &symbols_number);

    if (symbols_number == 3)
        printf("num_errors = %d\n", num_errors);
    else
        printf("Alright, let's move on to solving the equation.\n");
}


void sort_two_values(double *number1, double *number2)
{
    if (!isnan(*number1) && !isnan(*number2))
    {
        if (*number1 > *number2)
        {
            double temp = *number1;
            *number1 = *number2;
            *number2 = temp;
        }
    }
}




