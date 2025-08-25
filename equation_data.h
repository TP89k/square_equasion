#ifndef EQUATION_DATA_H
#define EQUATION_DATA_H

#include <stdio.h>
#include <math.h>
#include <TXLib.h>

// ���������
const int AMOUNT_OF_TESTS = 6;
const float EPSILON = 0.00001;

// ��������� ��� �������� ������ ���������
typedef struct
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int num_roots;
} Equation_data;

// ��������� �������� �������
int check_epsilon_neighborhood(double number, double program_number);
void print_equation(Equation_data equation_data);
Equation_data input();
double calc_discriminant(Equation_data equation_data);
Equation_data solve_quadratic_equation(Equation_data equation_data);
void print_results(Equation_data equation_data);

// ���������� �������� �������
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

void print_equation(Equation_data equation_data)
{
    printf("���������: %.4fx^2", equation_data.a);
    if (equation_data.b >= 0) {
        printf(" + %.4fx", equation_data.b);
    }
    else
    {
        printf(" - %.4fx", -(equation_data.b));
    }

    if (equation_data.c >= 0) {
        printf(" + %.4f = 0\n", equation_data.c);
    }
    else {
        printf(" - %.4f = 0\n", -(equation_data.c));
    }
}

Equation_data input()
{
    Equation_data equation_data;
    double a = NAN;
    double b = NAN;
    double c = NAN;

    printf("==== ������� ���������� ��������� ====\n");
    printf("������� ��� ����������� a,b,c (������ ����� � ����� ������):\n");

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    equation_data.a = a;
    equation_data.b = b;
    equation_data.c = c;

    printf("\n�� �����:\n");
    printf("������ ��������� a: %.4f\n", equation_data.a);
    printf("������ ��������� b: %.4f\n", equation_data.b);
    printf("������ ��������� c: %.4f\n", equation_data.c);

    return equation_data;
}

double calc_discriminant(Equation_data equation_data)
{
    return equation_data.b * equation_data.b - 4 * equation_data.a * equation_data.c;
}

Equation_data solve_quadratic_equation(Equation_data equation_data)
{
    double discriminant = calc_discriminant(equation_data);

    if (check_epsilon_neighborhood(equation_data.a, 0) == 1)
    {
        if (discriminant > 0 + EPSILON) {
            equation_data.num_roots = 2;
            equation_data.x1 = (-equation_data.b + sqrt(discriminant)) / (2 * equation_data.a);
            equation_data.x2 = (-equation_data.b - sqrt(discriminant)) / (2 * equation_data.a);
        }
        else if (check_epsilon_neighborhood(discriminant, 0) == 0) {
            equation_data.num_roots = 1;
            equation_data.x1 = equation_data.x2 = -equation_data.b / (2 * equation_data.a);
        }
        else {
            equation_data.num_roots = 0;
            equation_data.x1 = equation_data.x2 = 0;
        }
    }
    else if (check_epsilon_neighborhood(equation_data.a, 0) == 0)
    {
        if (check_epsilon_neighborhood(equation_data.b, 0) == 0) {
            if (check_epsilon_neighborhood(equation_data.c, 0) == 0) {
                equation_data.num_roots = -1;
                equation_data.x1 = equation_data.x2 = 0;
            }
            else {
                equation_data.num_roots = 0;
                equation_data.x1 = equation_data.x2 = 0;
            }
        }
        else {
            equation_data.num_roots = 1;
            equation_data.x1 = -equation_data.c / equation_data.b;
            equation_data.x2 = equation_data.x1;
        }
    }

    return equation_data;
}

void print_results(Equation_data equation_data)
{
    printf("\n==== ���������� ====\n");

    switch (equation_data.num_roots) {
        case -1:
            printf("��������� ����� ���������� ����� ������\n");
            break;
        case 0:
            printf("��������� �� ����� ������\n");
            break;
        case 1:
            printf("��������� ����� ���� ������:\n");
            printf("x = %.12f\n", equation_data.x1);
            break;
        case 2:
            printf("��������� ����� ��� �����:\n");
            printf("x1 = %.12f\n", equation_data.x1);
            printf("x2 = %.12f\n", equation_data.x2);
            break;
    }
}

#endif
