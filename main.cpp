#include <stdio.h>
#include <math.h>

#include "equation_data.h"
#include "equation_tests.h"  


int main() {
    Equation_data equation_data;

    #ifdef _DEBUG
        testing_program();
    #endif

    equation_data = input(&equation_data);
    print_equation(&equation_data); 
    equation_data = solve_quadratic_equation(&equation_data);
    print_results(&equation_data);
    
    printf("Программа завершена \n");
    printf(BOLD RED "COMMIT GITHUB\n" RESET);
    return 0; 
}
