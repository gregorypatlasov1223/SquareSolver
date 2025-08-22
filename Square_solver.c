#include <stdio.h>
#include <math.h>

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c);
int solver(double a, double b, double c, double *ptr_root1, double *ptr_root2);
void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2);

int main()
{
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double root_1 = 0, root_2 = 0;
    int nRoots = 0;

    printf("Let's solve an equation of the form ax2 + bx + c = 0.\n");

    input_coef(&coef_a, &coef_b, &coef_c);

    printf("Now let's move on to finding the roots.\n");

    nRoots = solver(coef_a, coef_b,coef_c, &root_1, &root_2);

    output_results(nRoots, &root_1, &root_2);

    return 0;
}

void input_coef(double *ptr_a, double *ptr_b, double *ptr_c)
{
    printf("Enter the coefficient a.\n");
    scanf("%lf", ptr_a);

    printf("Enter the coefficient b.\n");
    scanf("%lf", ptr_b);

    printf("Enter the coefficient c.\n");
    scanf("%lf", ptr_c);
}

int solver(double a, double b, double c, double *ptr_root1, double *ptr_root2)
{
    double discriminant = 0;

    if (fabs(a) < 0.00000001)
    {
        if (fabs(b) < 0.00000001)
        {
            if (fabs(c) < 0.00000001)
                return 1;
            else
                return 2;
        }

        else
        {
            *ptr_root1 = *ptr_root2 = -c/b;
            return 3;
        }
    }

    else
    {
        discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return 4;

        else if (discriminant > 0)
        {
            *ptr_root1 = (-b + sqrt(discriminant)) / (2 * a);
            *ptr_root2 = (-b - sqrt(discriminant)) / (2 * a);
            return 5;
        }

        else
        {
            *ptr_root1 = *ptr_root2 = -b / (2 * a);
            return 6;
        }

     }
}

void output_results(int number_of_roots, double *ptr_root1, double *ptr_root2)
{
    if (number_of_roots == 2 || number_of_roots == 4)
        printf("The equation has no solutions with the given coefficients!");

    if (number_of_roots == 3 || number_of_roots == 6)
        printf("The root of the equation is %lf.\n", *ptr_root1);

    if (number_of_roots == 5)
        printf("The roots of the equation are numbers %lf and %lf.\n", *ptr_root1, *ptr_root2);

    if (number_of_roots == 1)
        printf("An infinite number of solutions.");
}





