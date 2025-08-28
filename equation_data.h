#ifndef EQUATION_DATA_H
#define EQUATION_DATA_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

#include "equation_tests.h"
#include <stdio.h>
#include <math.h>


//----------------------------------------
//const int LANGUAGE - константа языка текста в консоли (0 - русский, 1 - English)
//----------------------------------------

const int LANGUAGE = 0;
  
//----------------------------------------
//const float EPSILON - константа эпсилон окрестности вычислений
//----------------------------------------

const float EPSILON = 0.00001;
 

//----------------------------------------
// Подструктура для коэффициентов
// double a - первый коэффицент при х^2
// double b - второй коэффицент при х
// double c - третий коэффицент 
//----------------------------------------

typedef struct
{
    double a;
    double b;
    double c;
} Coefficients;


//----------------------------------------
// Подструктура Roots для корней
// double x1 - первый корень
// double x2 - второй корень
// int num_roots - количество корней
//----------------------------------------

typedef struct
{
    double x1;
    double x2;
    int num_roots;
} Roots;


//----------------------------------------
// struct Equation_data - структура коэффицентов и корней уравнения
// coefficents - коэффициенты уравнения
// roots - корни уравнения и их количество
//----------------------------------------

typedef struct
{
    Coefficients coefficents;
    Roots roots;
} Equation_data;


int is_zero(double number, double program_number);
void print_equation(Equation_data *equation_data);
Equation_data input(Equation_data *equation_data);
double calc_discriminant(Equation_data *equation_data);
Equation_data solve_quadratic_equation();
void print_results(Equation_data *equation_data);
   
#endif
        