#include <stdio.h>
#include <math.h>
void solver(double a, double b, double c, double *ptr_root1, double *ptr_root2);
void input(double *ptr_a, double *ptr_b, double *ptr_c);
int main()
{
    double coef_a = 0, coef_b = 0, coef_c = 0;
    double root_1 = 0, root_2 = 0;

    printf("Let's solve an equation of the form ax2 + bx + c = 0.\n");

    input(&coef_a, &coef_b, &coef_c);

    printf("Now let's move on to finding the roots.\n");

    solver(coef_a, coef_b,coef_c, &root_1, &root_2);

    return 0;
}

void input(double *ptr_a, double *ptr_b, double *ptr_c)
{
    printf("Enter the coefficient a.\n");
    scanf("%lf", ptr_a);

    printf("Enter the coefficient b.\n");
    scanf("%lf", ptr_b);

    printf("Enter the coefficient c.\n");
    scanf("%lf", ptr_c);
}

void solver(double a, double b, double c, double *ptr_root1, double *ptr_root2)
{
    double discriminant;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("An infinite number of solutions.");
            else
                printf("The equation has no solutions with the given coefficients!");
        }

        else
        {
            *ptr_root1 = *ptr_root2 = -c/b;
            printf("The root of the equation is %lf.\n", *ptr_root1);
        }
    }

    else
    {
        discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            printf("The equation has no solutions with the given coefficients!\n");

        else if (discriminant > 0)
        {
            *ptr_root1 = (-b + sqrt(discriminant)) / (2 * a);
            *ptr_root2 = (-b - sqrt(discriminant)) / (2 * a);

            printf("The roots of the equation are numbers %lf and %lf.\n", *ptr_root1, *ptr_root2);
        }

        else
        {
            *ptr_root1 = *ptr_root2 = -b / (2 * a);
            printf("The equation has a single root = %lf.\n", *ptr_root1);
        }

     }
}





