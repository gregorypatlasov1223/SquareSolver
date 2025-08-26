#include <TXLib.h>
#include <stdio.h>
#include "Square_solver.h"

void input_coef(coeffs_data *coefficiant)
{
    /*assert(ptr_a);
    assert(ptr_b);
    assert(ptr_c);
    assert(ptr_a != ptr_b);
    assert(ptr_a != ptr_c);
    assert(ptr_b != ptr_c);*/

    printf("Let's solve an equation of the form ax2 + bx + c = 0.\n");

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
    printf("Input error!\n");
    clear_buffer();
    printf("Try again!\n");
}
