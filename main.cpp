#include <stdio.h>
#include <string.h>
#include "square_solver.h"
#include "colors_codes.h"
#include "test.h"
#include "stdbool.h"

int main(int argc, const char *argv[])
{
    printf("\nYou launch the program: %s\n", argv[0]);
    //bool arg_options[3] = {}; [0] = true
    //TODO function ParseArgv(arg_options)
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--test") == 0)
        {
            int passed = 0;
            int total_tests = 0;

            run_tests_from_file(&passed, &total_tests);

            return 0;
        }
    }
    //TODO: if (arg_options[0] == true)
    //          tests();
    printf("Normal execution mode. Use --test for tests.\n");

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
