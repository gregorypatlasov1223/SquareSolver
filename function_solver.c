#include <stdio.h>
#include <locale.h>
#include <math.h>
double input(double u, double v, double w);
int main(void)
{
	setlocale(LC_ALL, "Russian");
	printf("������� ����� ��������� ���� a*x*x + b*x +c=0.\n");
	double coef_1, coef_2, coef_3;
	coef_1=1;
	coef_2=2;
	coef_3=3;

	double discriminant;
	discriminant =input(coef_1, coef_2,coef_3 );
	printf("������������ ����� %ld.\n", discriminant );
	printf("������ ������ ����� ���������.");



	return 0;
}

double input(double u, double v, double w)
{
	double D;
	printf("������� ����������� a.\n");
	scanf("%lf", &u);
	printf("������� ����������� b.\n");
	scanf("%lf", &v);
	printf("������� ����������� c.\n");
	scanf("%lf", &w);
	D = v * v - 4 * u * w;
	return D;

}

