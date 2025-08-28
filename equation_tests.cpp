#include "equation_tests.h"


//----------------------------------------
//@param [out] вывод нового вида файла
//----------------------------------------

void input_tests() 
{
    FILE *file;
    const char *file_name = "tests.txt";

    char text[1000];

    printf("Введите строку: ");
    fgets(text, sizeof(text), stdin);

    for(int i = 0; text[i] != '\0'; i++) {
        if(text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    file = fopen(file_name, "a");
    if (file == NULL) {
        printf("Ошибка открытия файла '%s' для добавления!\n", file_name);
        return;
    }

    fprintf(file, "%s\n", text);

    fclose(file);

    printf("Записать новые тесты? Y/N\n");
    int p = getchar();
    if ((p=='Y') || (p=='y')){
        input_tests();
    }
    else {
        printf("Запись тестов завершена\n");
    }
}


//----------------------------------------
//@param [in] const char *file_name - имя файла
//@param [in] int *line_number - номер строки
//@param [in] double *result_array - массив для записи строки
//@param [out] тестовое значение -1 в случае ошибки
//----------------------------------------

int scan_one_test(const char *filename, int *line_number, double *result_array) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1; 
    }
    
    char line[1000];
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
    return -1; 
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

    equation_data = solve_quadratic_equation(&equation_data);

    printf("Тестовые значения: %.4f %.4f %.0f\n", one_test_data[3], one_test_data[4], one_test_data[5]);
    printf("Ожидаемые значения: %.4f %.4f %.0f\n", equation_data.roots.x1, equation_data.roots.x2,  equation_data.roots.num_roots);

    if ( ((is_zero(equation_data.roots.x1, one_test_data[3])==0) &&
        (is_zero(equation_data.roots.x2, one_test_data[4])==0) &&
        (one_test_data[5] == equation_data.roots.num_roots)) || ((is_zero(equation_data.roots.x2, one_test_data[3])==0) &&
        (is_zero(equation_data.roots.x1, one_test_data[4])==0) &&
        (one_test_data[5] == equation_data.roots.num_roots)) ) {
        printf(MAGENTA "Корректно\n" RESET);
        return 1;
    }
    else {
        printf(RED "Выявлена ошибка!\n" RESET);
        return 0;
    }
}


//----------------------------------------
//@param [out] int not_failed количество верно пройденных тестов
//----------------------------------------

int run_test()
{
    const char *file_name = "tests.txt";
    FILE *file = fopen(file_name, "r");

    int lines_quantity = count_lines_in_file(file_name);

    printf("Количество тестовых примеров %d\n", lines_quantity);

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
//@param [out] количество верно пройденных тестов
//----------------------------------------

void testing_program()
{
    const char *file_name = "tests.txt";
    
    int count_tests = run_test();

    printf("ПРОЙДЕНО ТЕСТОВ: %d", count_tests);
    printf(" ИЗ %d\n", count_lines_in_file(file_name));

    input_tests();
} 