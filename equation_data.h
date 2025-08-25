#ifndef EQUATION_DATA_H
#define EQUATION_DATA_H

#include "equation_tests.h"
#include <stdio.h>
#include <math.h>

  
//----------------------------------------
//const int AMOUNT_OF_TESTS - размер массива тестовых примеров
//----------------------------------------

const int AMOUNT_OF_TESTS = 6;


//----------------------------------------
//const float EPSILON - константа эпсилон окрестности вычислений
//----------------------------------------

const float EPSILON = 0.00001;


//----------------------------------------
// struct Equation_data - структура коэффицентов и корней уравнения + количество корней
// a первый коэффицент уравнения a
// b второй коэффицент уравнения b
// c третий коэффицент уравнения c
// x1 первый корень уравнения
// x2 второй корень уравнения
// num_roots количество корней
//----------------------------------------

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
