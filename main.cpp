#include <stdio.h>
#include <math.h>

#include "equation_data.h"
#include "equation_tests.h"
  


int main() {
    
    Equation_data equation_data;

    testing_program();

    equation_data = input();

    equation_data = solve_quadratic_equation(equation_data);
    print_results(equation_data);
    
    return 0;
}
