#ifndef EQUATION_TESTS_H
#define EQUATION_TESTS_H

#include "equation_data.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


//----------------------------------------
//const int AMOUNT_OF_TESTS - размер массива тестовых примеров
//----------------------------------------

const int AMOUNT_OF_TESTS = 10000;  


void input_tests();
int scan_one_test(const char *filename, int *line_number, double *result_array);
int count_lines_in_file(const char *file_name);
int run_one_test(double one_test_data[6]);
int run_test();
void testing_program();  

#endif 

  