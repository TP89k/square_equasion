#include "equation_tests.h"

#include <stdio.h>
#include <stdlib.h>


//----------------------------------------
//@param [in] const char *file_name - имя файла
//@param [in] int *line_number номер строки
//@param [in] double *result_array - строка в виде массива
//@param [out] int parsed_count - проверка на количество считанных элементов
//----------------------------------------
 
int scan_one_test(const char *filename, int *line_number, double *result_array) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1; 
    }
    
    char line[1024];
    int current_line = 1;
    
    while (fgets(line, sizeof(line), file) != NULL) {
        if (current_line == *line_number) {
            fclose(file);
            
            int parsed_count = sscanf(line, "%lf %lf %lf %lf %lf %lf",
                                    &result_array[0], &result_array[1], &result_array[2],
                                    &result_array[3], &result_array[4], &result_array[5]);
            
            return parsed_count; 
        }
        current_line++;
    }
    
    fclose(file);
    return -2; 
}


//----------------------------------------
//@param [in] const char *file_name - имя файла
//@param [out] int line_count - количество не пустых строк файла
//----------------------------------------

int count_lines_in_file(const char *file_name)
{

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return -1;
    }
    
    int chr;
    int line_count = 0;
    int current_line_has_numbers = 0;
    
    while ((chr = fgetc(file)) != EOF) {
        if (chr == '\n') {
            if (current_line_has_numbers==1) {
                line_count++;
            }
            current_line_has_numbers = 0;
        } else if (!isspace(chr)) {
            current_line_has_numbers = 1;
        }
    }
    
    if (current_line_has_numbers) {
        line_count++;
    }
    
    fclose(file);
    return line_count;
}


//----------------------------------------
//@param [in] const char *file_name - имя файла
//@param [in] double test_data[AMOUNT_OF_TESTS][6] - массив тестовых примеров
//@param [out] 1, если тестовый файл верно записан, иначе 0
//----------------------------------------

int read_tests_from_file(const char *file_name, double test_data[AMOUNT_OF_TESTS][6], int *line_count) {
    FILE *file = fopen(file_name, "r");
    
    for (int i = 0; i < *line_count; i++) {
        for (int j = 0; j < 6; j++) {
            if (fscanf(file, "%lf", &test_data[i][j]) != 1) {
                printf("Ошибка чтения данных из файла (строка %d)\n", i+1);
                fclose(file);
                return 0; 
            }
        }   
    }
    
    fclose(file);
    return 1; 
}


//----------------------------------------
//@param [in] int *number_of_line - количество не пустых строк в файле
//@param [in] const char *file_name - имя файла с тестами
//@param [out] 1, если тестовые корни совпадают с настоящим, иначе 0
//----------------------------------------

int run_one_test(double one_test_data[6])
{
    Equation_data equation_data;

    equation_data.coefficents.a = one_test_data[0];
    equation_data.coefficents.b = one_test_data[1];
    equation_data.coefficents.c = one_test_data[2];

    equation_data = solve_quadratic_equation(equation_data);

    if ( ((is_zero(equation_data.roots.x1, one_test_data[3])==0) &&
        (is_zero(equation_data.roots.x2, one_test_data[4])==0) &&
        (one_test_data[5] == equation_data.roots.num_roots)) || ((is_zero(equation_data.roots.x2, one_test_data[3])==0) &&
        (is_zero(equation_data.roots.x1, one_test_data[4])==0) &&
        (one_test_data[5] == equation_data.roots.num_roots)) ) {
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

    int lines_quantity = count_lines_in_file(file_name);

    printf("Количество тестовых примеров %d\n", lines_quantity);

    double test_data[AMOUNT_OF_TESTS][6];
    //read_tests_from_file(file_name, test_data, &lines_quantity);

    double one_test_data[6];

    int not_failed = 0;
    for (int i = 1; i < lines_quantity+1; i++)
    {
        scan_one_test(file_name, &i, one_test_data);
        not_failed += run_one_test(one_test_data);
    }

    return not_failed;
}
  

//----------------------------------------
//[out] количество верно пройденных тестов
//----------------------------------------

void testing_program()
{
    const char *file_name = "tests.txt";
    
    int count_tests = run_test();
  
    printf("ПРОЙДЕНО ТЕСТОВ: %d", count_tests);
    printf(" ИЗ %d\n", count_lines_in_file(file_name));
} 