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
	printf("������� ������������ a,b � c ����������� ��������� ���� a*x*x+b*x+c=0.\n");
	printf("��� ���������� ��������� ������� f.\n");
	printf("������� ����������� a.\n");
	scanf("%lf", &a);
	printf("������� ����������� b.\n");
	scanf("%lf", &b);
	printf("������� ����������� c.\n");
	scanf("%lf", &c);
	D= b * b - 4 * a * c;

	while ((ch = getchar()) != 'f')
	{
		if (D < 0)
			printf("������� ���!\n");

		else if (D > 0)
		{
			x1 = (-b + sqrt(D)) / 2 * a;
			x2 = (-b - sqrt(D)) / 2 * a;
			printf("������� ��������� �������� ����� %lf � %lf.\n", x1, x2);
		}

		else
		{
			x0 = (-b + sqrt(D)) / 2 * a;
			printf("��������� ����� ������������ ������ = %lf.\n", x0);
		}
		printf("�������� ������ ������������ ��������� ��� ������� f ��� ����������.\n");
	}


	return 0;


}
