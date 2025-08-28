#ifndef EQUATION_TESTS_H
#define EQUATION_TESTS_H

#include "equation_data.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


void input_tests();
int scan_one_test(int *line_number, double *result_array);
int count_lines_in_file();
int run_one_test(double one_test_data[6]);
int run_test(int *lines_in_file);
void testing_program();  

#endif 

  