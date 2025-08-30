#include <stdio.h>
#include <string.h>
#include "square_solver.h"
#include "colors_codes.h"
#include "input.h"
#include "stdbool.h"
#include "interactive.h"

void interactive()
{
    coeffs_data coeffs = {};

    roots_data roots = {};

    printf(RED "COMMIT GITHUB!\n" RESET);

    input_coef(&coeffs);

    printf(YELLOW "Now let's move on to finding the roots.\n" RESET);

    roots.nRoots = solve_equation(coeffs, &roots);

    output_results(&roots);
}
