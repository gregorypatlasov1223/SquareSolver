#include <stdio.h>
#include "square_solver.h"
#include "colors_codes.h"
#include "input.h"

void input_coef(coeffs_data *coefficient)
{
    printf(YELLOW "Let's solve an equation of the form ax^2 + bx + c = 0.\n" RESET);

    printf("Enter the coefficient a.\n");
    while (scanf("%lg", &(coefficient->a)) != 1)
        error_output();

    printf("Enter the coefficient b.\n");
    while (scanf("%lg", &(coefficient->b)) != 1)
        error_output();

    printf("Enter the coefficient c.\n");
    while (scanf("%lg", &(coefficient->c)) != 1)
        error_output();
}

void error_output()
{
    printf(RED "Input error!\n" RESET);
    clear_buffer();
    printf(RED "Try again!\n" RESET);
}

void clear_buffer()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n' && symbol != EOF)
        continue;
}
