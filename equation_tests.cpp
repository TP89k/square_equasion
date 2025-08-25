#include "equation_tests.h"

#include <stdio.h>
#include <stdlib.h>



int read_array_from_file(const char *file_name, double test_data[AMOUNT_OF_TESTS][6]) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла \n");
        return 0; 
    }
    
    for (int i = 0; i < AMOUNT_OF_TESTS; i++) {
        for (int j = 0; j < 6; j++) {
            if (fscanf(file, "%lf", &test_data[i][j]) != 1) {
                printf("Ошибка чтения данных из файла (строка %d\n", i+1);
                fclose(file);
                return 0; 
            }
        }
    }
    
    fclose(file);
    return 1; 
}


//----------------------------------------
//@param [in] double a  коэффицент а
//@param [in] double b  коэффицент b
//@param [in] double c  коэффицент c
//@param [in] double x1_specified  тестовый корень 1
//@param [in] double x2_specified  тестовый корень 2
//@param [in] int number_of_solutions  количество тестовых корней
//@param [out] 1, если тестовые корни совпадают с настоящим, иначе 0
//----------------------------------------

int run_one_test(double *a, double *b, double *c, double *x1_specified, double *x2_specified, double *number_of_solutions)
{
    Equation_data equation_data;

    equation_data.coefficents.a = *a;
    equation_data.coefficents.b = *b;
    equation_data.coefficents.c = *c;

    equation_data = solve_quadratic_equation(equation_data);

    if ((check_epsilon_neighborhood(equation_data.roots.x1, *x1_specified)==0) &&
        (check_epsilon_neighborhood(equation_data.roots.x2, *x2_specified)==0) &&
        (*number_of_solutions == equation_data.roots.num_roots)) {
        return 1;
    }
    else {
        return 0;
    }
}


//----------------------------------------
//@param [out] int not_failed количество верно пройденных тестов
//----------------------------------------

int run_test()
{
    const char *file_name = "tests.txt";
    double test_data[AMOUNT_OF_TESTS][6];
    read_array_from_file(file_name, test_data);

    int not_failed = 0;
    for (int i = 0; i < AMOUNT_OF_TESTS; i++)
    {
        not_failed += run_one_test(&test_data[i][0], &test_data[i][1], &test_data[i][2],
                                 &test_data[i][3], &test_data[i][4], &test_data[i][5]);
    }

    return not_failed;
}


//----------------------------------------
//[out] количество верно пройденных тестов
//----------------------------------------

void testing_program()
{
    int count_tests = run_test();
  
    printf("ПРОЙДЕНО ТЕСТОВ: %d", count_tests);
    printf(" ИЗ %d\n", AMOUNT_OF_TESTS);
} 