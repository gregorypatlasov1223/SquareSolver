#include <stdio.h>
#include "square_solver.h"
#include "colors_codes.h"

void input_coef(coeffs_data *coefficiant)
{
    printf(YELLOW "Let's solve an equation of the form ax^2 + bx + c = 0.\n" RESET);

    printf("Enter the coefficient a.\n");
    while (scanf("%lg", &(coefficiant->a)) != 1)
        error_output();

    printf("Enter the coefficient b.\n");
    while (scanf("%lg", &(coefficiant->b)) != 1)
        error_output();

    printf("Enter the coefficient c.\n");
    while (scanf("%lg", &(coefficiant->c)) != 1)
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
