#ifndef SQUARE_SOLVER_H_
#define SQUARE_SOLVER_H_

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

NumberSolutions solve_equation(coeffs_data coefficient, roots_data *ptr_root);
NumberSolutions square_equation(coeffs_data coefficient, roots_data *ptr_root);
NumberSolutions linear_equation(coeffs_data coefficient, roots_data *ptr_root);

void output_results(roots_data *solutions);

bool compare_double(double number1, double number2);

#endif  // SQUARE_SOLVER_H_
