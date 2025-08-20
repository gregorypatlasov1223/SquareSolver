#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void solver(double x, double y, double z, double n);
double input(double u, double v, double w);
int main(void)
{
	printf("����� ��������� ���� a*x*x + b*x + c = 0.\n");
	double coef_1, coef_2, coef_3;
	coef_1=1;
	coef_2=2;
	coef_3=3;

	double discriminant;
	discriminant =input(coef_1, coef_2,coef_3 );
	printf("������ �������� � ���������� ������ ���������.");
    solver(discriminant,coef_1, coef_2,coef_3);


	return 0;
}

double input(double u, double v, double w)  // ��������� ��� ����� ������������� � ���������� �������������
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
 void solver(double x, double y, double z, double n)    // ��������� �� ������� ����������� ���������
 {
    char ch;
    double root_0, root_1, root_2;
    while ((ch = getchar()) != 'f')
    {
	if (x < 0)
		printf("��� �������� ������������� ��������� �� ����� �������!\n");

	else if (x > 0)
	{
		root_1 = (-z + sqrt(x)) / (2 * y);
		root_2 = (-z - sqrt(x)) / (2 * y);
		printf("������� ��������� �������� ����� %lf � %lf.\n", root_1, root_2);
	}

	else
	{
		root_0 = (-z + sqrt(x)) /(2 * y);
		printf("��������� ����� ������������ ������ = %lf.\n", root_0);
	}

	if (y==0)
    {
        root_0 = -n/z;
        printf("������ ��������� ����� %lf.\n", root_0);
    }

	printf("�������� ������ ������������ ��������� ��� ������� f ��� ����������.\n");
    }
 }



