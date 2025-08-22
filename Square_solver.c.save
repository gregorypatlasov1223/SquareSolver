#include <stdio.h>
#include <math.h>
void solver(double x, double y, double z);
double input(double u, double v, double w);
int main(void)
{
	printf("Let's solve an equation of the form a*x*x + b*x + c = 0.\n");
	double coef_a, coef_b, coef_c;
	coef_a=0;
	coef_b=0;
	coef_c=0;


	input(coef_a, coef_b,coef_c);
	printf("Now let's move on to finding the roots.\n");
    solver(coef_a, coef_b,coef_c);



	return 0;
}

double input(double u, double v, double w)  // программа для ввода коэффициентов
{
	double D;
	printf("Enter the coefficient a.\n");
	scanf("%lf", &u);
	printf("Enter the coefficient b.\n");
	scanf("%lf", &v);
	printf("Enter the coefficient c.\n");
	scanf("%lf", &w);


}
 void solver(double x, double y, double z)    // программа по решению квадратного уравнения
 {
    char ch;
    double root_0, root_1, root_2;
    double D;
    D = y * y - 4 * x * z;

    while ((ch = getchar()) != 'f')
    {
	if (D < 0)
		printf("The equation has no solutions with the given coefficients!\n");

	else if (D > 0)
	{
		root_1 = (-y + sqrt(D)) / (2 * x);
		root_2 = (-y - sqrt(D)) / (2 * x);
		printf("The roots of the equation are numbers %lf и %lf.\n", root_1, root_2);
	}
    else
	{
		root_0 = -y/(2 * x);
		printf("The equation has a single root = %lf.\n", root_0);
	}
    if (x==0)
    {
        root_0 = -z/y;
        printf("The root of the equation is %lf.\n", root_0);
    }

	printf("Write another coefficients of the equation or press f to stop the programme.\n");
    }
 }



