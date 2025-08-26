#ifndef EQUATION_TESTS_H
#define EQUATION_TESTS_H

#include "equation_data.h"


  
//----------------------------------------
//const int AMOUNT_OF_TESTS - размер массива тестовых примеров
//----------------------------------------

const int AMOUNT_OF_TESTS = 10;  


int read_array_from_file(const char *file_name, double test_data[AMOUNT_OF_TESTS][6]);
int run_one_test(double *a, double *b, double *c, double *x1_specified, double *x2_specified, double *number_of_solutions);
int run_test();
void testing_program();  

#endif 

  