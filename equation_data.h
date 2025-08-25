#ifndef EQUATION_DATA_H
#define EQUATION_DATA_H

#include "equation_tests.h"
#include <stdio.h>
#include <math.h>


const int AMOUNT_OF_TESTS = 6;
const float EPSILON = 0.00001;


typedef struct
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int num_roots;
} Equation_data;


int check_epsilon_neighborhood(double number, double program_number);
void print_equation(Equation_data equation_data);
Equation_data input();
double calc_discriminant(Equation_data equation_data);
Equation_data solve_quadratic_equation(Equation_data equation_data);
void print_results(Equation_data equation_data);

#endif
