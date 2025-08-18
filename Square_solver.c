#include <stdio.h>
#include <locale.h>
#include <math.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	char ch;
	double a, b, c;
	double D;
	double x0, x1, x2;
	printf("Введите коэффициенты a,b и c квадратного уравнения вида a*x*x+b*x+c=0.\n");
	printf("Для завершения программы нажмите f.\n");
	printf("Введите коэффициент a.\n");
	scanf("%lf", &a);
	printf("Введите коэффициент b.\n");
	scanf("%lf", &b);
	printf("Введите коэффициент c.\n");
	scanf("%lf", &c);
	D= b * b - 4 * a * c;

	while ((ch = getchar()) != 'f')
	{
		if (D < 0)
			printf("Решений нет!\n");

		else if (D > 0)
		{
			x1 = (-b + sqrt(D)) / 2 * a;
			x2 = (-b - sqrt(D)) / 2 * a;
			printf("Корнями уравнения являются числа %lf и %lf.\n", x1, x2);
		}

		else
		{
			x0 = (-b + sqrt(D)) / 2 * a;
			printf("Уравнение имеет единственный корень = %lf.\n", x0);
		}
		printf("Напишите другие коэффициенты уравнения или нажмите f для завершения.\n");
	}


	return 0;


}
