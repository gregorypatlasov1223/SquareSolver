#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void solver(double x, double y, double z, double n);
double input(double u, double v, double w);
int main(void)
{
	printf("Решим уравнение вида a*x*x + b*x + c = 0.\n");
	double coef_1, coef_2, coef_3;
	coef_1=1;
	coef_2=2;
	coef_3=3;

	double discriminant;
	discriminant =input(coef_1, coef_2,coef_3 );
	printf("Теперь перейдем к нахождению корней уравнения.");
    solver(discriminant,coef_1, coef_2,coef_3);


	return 0;
}

double input(double u, double v, double w)  // программа для ввода коэффициентов и вычисления дискриминанта
{
	double D;
	printf("Введите коэффициент a.\n");
	scanf("%lf", &u);
	printf("Введите коэффициент b.\n");
	scanf("%lf", &v);
	printf("Введите коэффициент c.\n");
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
		printf("При заданных коэффициентах уравнение не имеет решений!\n");

	else if (x > 0)
	{
		root_1 = (-z + sqrt(x)) / (2 * y);
		root_2 = (-z - sqrt(x)) / (2 * y);
		printf("Корнями уравнения являются числа %lf и %lf.\n", root_1, root_2);
	}

	else
	{
		root_0 = (-z + sqrt(x)) /(2 * y);
		printf("Уравнение имеет единственный корень = %lf.\n", root_0);
	}

	if (y==0)
    {
        root_0 = -n/z;
        printf("Корень уравнения равен %lf.\n", root_0);
    }

	printf("Напишите другие коэффициенты уравнения или нажмите f для завершения.\n");
    }
 }



