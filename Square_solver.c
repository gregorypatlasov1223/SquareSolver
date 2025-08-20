#include <stdio.h>
#include <math.h>
void solver(double x, double y, double z, double n);
double input(double u, double v, double w);
int main(void)
{
	printf("Let's solve an equation of the form a*x*x + b*x + c = 0.\n");
	double coef_a, coef_b, coef_c;
	coef_a=1;
	coef_b=2;
	coef_c=3;

	double discriminant;
	discriminant =input(coef_a, coef_b,coef_c );
	printf("Now let's move on to finding the roots.");
    solver(discriminant,coef_a, coef_b,coef_c);


	return 0;
}

double input(double u, double v, double w)  // программа для ввода коэффициентов и вычисления дискриминанта
{
	double D;
	printf("Enter the coefficient a.\n");
	scanf("%lf", &u);
	printf("Enter the coefficient b.\n");
	scanf("%lf", &v);
	printf("Enter the coefficient c.\n");
	scanf("%lf", &w);
	D = v * v - 4 * u * w;
	return D;

}
 void solver(double x, double y, double z, double n)    // программа по решению квадратного уравнения
 {
    char ch;
    double root_0, root_1, root_2;
    while ((ch = getchar()) != 'f')
    {
	if (x < 0)
		printf("The equetion has no solutions with the given coefficitnts!\n");

	else if (x > 0)
	{
		root_1 = (-z + sqrt(x)) / (2 * y);
		root_2 = (-z - sqrt(x)) / (2 * y);
		printf("The roots of the equation are numbers %lf and %lf.\n", root_1, root_2);
	}

	else
	{
		root_0 = (-z + sqrt(x)) /(2 * y);
		printf("The equation has a single root = %lf.\n", root_0);
	}

	if (y==0)
    {
        root_0 = -n/z;
        printf("The root of the equation is %lf.\n", root_0);
    }

	printf("Write another coefficients og the equation or press f to stop the programme.\n");
    }
 }



