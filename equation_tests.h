#ifndef EQUATION_TESTS_H
#define EQUATION_TESTS_H

#include "equation_data.h"
#include <stdio.h>
#include <ctype.h>


  
//----------------------------------------
//const int AMOUNT_OF_TESTS - размер массива тестовых примеров
//----------------------------------------

const int AMOUNT_OF_TESTS = 10000;  

int read_array_from_file(const char *file_name, double test_data[AMOUNT_OF_TESTS][6], int *line_count);
int read_array_from_file(const char *file_name, double test_data[AMOUNT_OF_TESTS][6]);
int run_one_test(int *number_of_line, double test_data[AMOUNT_OF_TESTS][6]);
int run_test();
void testing_program();  

#endif 

  