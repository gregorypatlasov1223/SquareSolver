#ifndef PARSE_FLAGS_H_
#define PARSE_FLAGS_H_

enum FlagTypes
{
    HELP_FLAG,
    TEST_FLAG,
    INTERACTIVE_FLAG
};

void run_tests_from_file();
FlagTypes parse_flags(int argc, char *argv[]);
void show_help();

#endif  // PARSE_FLAGS_H_
