enum NumberSolutions
{
    NO_ROOTS       =  0,
    ONE_ROOT       =  1,
    TWO_ROOTS      =  2,
    INFINITE_ROOTS = -1
};

struct coeffs_data
{
    double a;
    double b;
    double c;
};

struct roots_data
{
    double x1;
    double x2;
    NumberSolutions nRoots;
};

const double ERROR_RATE = 10e-15;

void user_wishes();

int run_test();

int one_test(coeffs_data t_coeffs, roots_data *expected_roots);

void input_coef(coeffs_data *coefficiant);

void error_output();

NumberSolutions solve_equation  (coeffs_data coefficiant, roots_data *ptr_root);
NumberSolutions square_equation (coeffs_data coefficiant, roots_data *ptr_root);
NumberSolutions linear_equation (coeffs_data coefficiant, roots_data *ptr_root);

void output_results(roots_data *solutions);

bool compare_double(double number1, double number2);

void sort_two_values(double *x1, double *x2);

void poltorashka(const char *name);

void clear_buffer();
