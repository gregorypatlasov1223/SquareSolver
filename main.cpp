#include <TXLib.h>
#include <stdio.h>
#include "square_solver.h"
#include "colors_codes.h"

int main(int argc, const char *argv[])
{
    printf("\nYou launch the program: %s\n", argv[0]); //TODO check argc

    printf("Total arguements: %d\n", argc); //TODO use argv to read test

    coeffs_data coeffs = {};

    roots_data roots = {};

    printf(RED "COMMIT GITHUB!\n" RESET);

    user_answer();

    input_coef(&coeffs);

    printf(YELLOW "Now let's move on to finding the roots.\n" RESET);

    roots.nRoots = solve_equation(coeffs, &roots);

    output_results(&roots);

    return 0;
}
