#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "square_solver.h"
#include "colors_codes.h"
#include "test.h"
#include "parse_flags.h"
#include "interactive.h"

void show_help()
{
    printf(BLUE "\nYou have launched a program for solving quadratic equations.\n"
                   "Click \"make\" to start the program\n"
                   "There are 3 commands in total:\n"
                   "Click \"--test\" to display the results of unit tests\n"
                   "Click \"--interactive\" to run the program without calculating unot tests\n"
                   "Click \"--help\" to open the help window\n" RESET);
}

void run_tests_from_file()
{
    int passed = 0;
    int total_tests = 0;

    FILE* file = open_file_and_check("test.txt", "rb");

    if (file == NULL)
        return;

    int change_for_nRoots = 0;

    coeffs_data coeffs = {};
    roots_data roots   = {};

    while (true)
    {
        int num_of_symbols = fscanf(file, "%lg %lg %lg %lg %lg %d",
                                    &coeffs.a, &coeffs.b, &coeffs.c,
                                    &roots.x1, &roots.x2, &change_for_nRoots);

        if (num_of_symbols != 6)
            break;

        roots.nRoots = (NumberSolutions)change_for_nRoots;

        total_tests++;
        passed += one_test(coeffs, &roots);
    }

    printf(GREEN "\nResults: %d from %d tests completed\n" RESET, passed, total_tests);

    fclose(file);
}

FlagTypes parse_flags(int argc, char *argv[])
{
    int opt;
    int help_flag = 0;
    int test_flag = 0;
    int interactive_flag = 0;

    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"test", no_argument, 0, 't'},
        {"interactive", no_argument, 0, 'i'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "hti", long_options, NULL)) != -1)
    {
        switch (opt)
        {
            case 'h':
                help_flag = 1;
                break;
            case 't':
                test_flag = 1;
                break;
            case 'i':
                interactive_flag = 1;
                break;
            default:
                fprintf(stderr, "Use \"--help\" to get help.\n");
                help_flag = 1;
                break;
        }
    }

    if (help_flag)
        return HELP_FLAG;

    if (test_flag)
        return TEST_FLAG;

    if (interactive_flag)
        return INTERACTIVE_FLAG;

    return HELP_FLAG;
}


