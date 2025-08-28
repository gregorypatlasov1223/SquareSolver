#include <stdio.h>
#include "square_solver.h"
#include "colors_codes.h"

void output_results(roots_data *solutions)
{
    switch(solutions->nRoots)
    {
        case NO_ROOTS:
            printf(GREEN "The equation has no solutions with the given coefficients!" RESET);
            break;

        case ONE_ROOT:
            printf(GREEN "The root of the equation is %lg.\n" RESET, solutions->x1);
            break;

        case TWO_ROOTS:
            printf(GREEN "The roots of the equation are numbers %lg and %lg.\n" RESET, solutions->x1, solutions->x2);
            break;

        case INFINITE_ROOTS:
            printf(GREEN "An infinite number of solutions." RESET);
            break;

        default :
            printf(GREEN "Interesting choice!" RESET);
    }
}
