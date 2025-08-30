#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "square_solver.h"
#include "colors_codes.h"
#include "test.h"
#include "parse_flags.h"
#include "interactive.h"

int main(int argc, char *argv[])
{
    FlagTypes status = HELP_FLAG;

    status = parse_flags(argc, argv);

    switch (status)
    {
        case HELP_FLAG:
            show_help();
            break;
        case TEST_FLAG:
            run_tests_from_file();
            break;
        case INTERACTIVE_FLAG:
        default:
            interactive();
            break;
    }

    return 0;
}







