#include "equation_data.h"
#include <stdio.h>
#include <math.h>

  
//----------------------------------------
//@param [in] double number число, для которого проверяется эпсилон окрестность
//@param [in] double program_number число, вокруг которого проверяется эпсилон окрестность
//[out] int число (1 - если True и 0 - если False)
//----------------------------------------

int check_epsilon_neighborhood(double number, double program_number)
{
    if (!((number < program_number + EPSILON) && (number > program_number - EPSILON)))
    {
        return 1;
    }  
    else
    {
        return 0;
    }
}


//----------------------------------------
//@param [in] Equation_data - структура коэффицентов и корней уравнения + количество корней
//[out] вывод вида уравнения на экран пользователя
//----------------------------------------

void print_equation(Equation_data *equation_data)
{
    printf("Уравнение: %.4fx^2", (*equation_data).coefficents.a);
    if ((*equation_data).coefficents.b >= 0) {
        printf(" + %.4fx", (*equation_data).coefficents.b);
    }
    else
    {
        printf(" - %.4fx", -((*equation_data).coefficents.b));
    }

    if ((*equation_data).coefficents.c >= 0) {
        printf(" + %.4f = 0\n", (*equation_data).coefficents.c);
    }
    else {
        printf(" - %.4f = 0\n", -((*equation_data).coefficents.c));
    }
}


//----------------------------------------
//@param [out] Equation_data - структура коэффицентов и корней уравнения + количество корней
//----------------------------------------

Equation_data input(Equation_data *equation_data)
 {

    double a = NAN;
    double b = NAN;
    double c = NAN;

    printf("==== РЕШЕНИЕ КВАДРАТНЫХ УРАВНЕНИЙ ====\n");
    printf("Введите три коэффицента a,b,c (каждое число с новой строки):\n");

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    (*equation_data).coefficents.a = a;
    (*equation_data).coefficents.b = b;
    (*equation_data).coefficents.c = c;

    printf("\nВы ввели:\n");
    printf("Первый коэфицент a: %.4f\n", (*equation_data).coefficents.a);
    printf("Второй коэфицент b: %.4f\n", (*equation_data).coefficents.b);
    printf("Третий коэфицент c: %.4f\n", (*equation_data).coefficents.c);

    return *equation_data;
 }


//----------------------------------------
//@param [in] Equation_data - структура коэффицентов и корней уравнения + количество корней
//@param [out] discriminant вывод дискриминанта уравнения
//----------------------------------------

double calc_discriminant(Equation_data *equation_data)
{
    return (*equation_data).coefficents.b * (*equation_data).coefficents.b - 4 * (*equation_data).coefficents.a * (*equation_data).coefficents.c;
}


//----------------------------------------
//@param [in] Equation_data - структура коэффицентов и корней уравнения + количество корней
//@param [out] Equation_data - структура коэффицентов и корней уравнения + количество корней
//----------------------------------------

Equation_data solve_quadratic_equation(Equation_data equation_data)
{
    double discriminant = calc_discriminant(&equation_data);

    if (check_epsilon_neighborhood(equation_data.coefficents.a, 0)==1)
    {
        if (discriminant > 0+EPSILON) {
            equation_data.roots.num_roots = 2;
            equation_data.roots.x1 = (-equation_data.coefficents.b + sqrt(discriminant)) / (2 * equation_data.coefficents.a);
            equation_data.roots.x2 = (-equation_data.coefficents.b - sqrt(discriminant)) / (2 * equation_data.coefficents.a);
        }
        else if (check_epsilon_neighborhood(discriminant, 0)==0) {
            equation_data.roots.num_roots = 1;
            equation_data.roots.x1 = equation_data.roots.x2 = -equation_data.coefficents.b / (2 * equation_data.coefficents.a);
        }
        else {
            equation_data.roots.num_roots = 0;
            equation_data.roots.x1 = equation_data.roots.x2 = 0;
        }
    }
    else if (check_epsilon_neighborhood(equation_data.coefficents.a, 0)==0)
    {
        if (check_epsilon_neighborhood(equation_data.coefficents.b, 0)==0) {
            if (check_epsilon_neighborhood(equation_data.coefficents.c, 0)==0) {
                equation_data.roots.num_roots = -1;
                equation_data.roots.x1 = equation_data.roots.x2 = 0;
            }
            else {
                equation_data.roots.num_roots = 0;
                equation_data.roots.x1 = equation_data.roots.x2 = 0;
            }
        }
        else {
            equation_data.roots.num_roots = 1;
            equation_data.roots.x1 = -equation_data.coefficents.c / equation_data.coefficents.b;
            equation_data.roots.x2 = equation_data.roots.x1;
        }
    }

    return equation_data;
}


//----------------------------------------
//@param [in]  Equation_data - структура коэффицентов и корней уравнения + количество корней
//@param [in]  x1 первый корень уравнения
//@param [in]  x2 второй корень уравнения
//----------------------------------------

void print_results(Equation_data *equation_data)
{
    printf("\n==== РЕЗУЛЬТАТЫ ====\n");

    switch (  ((*equation_data).roots).num_roots) {
        case -1:
            printf("Уравнение имеет бесконечно много корней\n");
            break;
        case 0:
            printf("Уравнение не имеет корней\n");
            break;
        case 1:
            printf("Уравнение имеет один корень:\n");
            printf("x = %.20f\n", (*equation_data).roots.x1);
            break;
        case 2:
            printf("Уравнение имеет два корня:\n");
            printf("x1 = %.20f\n", (*equation_data).roots.x1);
            printf("x2 = %.20f\n", (*equation_data).roots.x2);
            break;
    }
}