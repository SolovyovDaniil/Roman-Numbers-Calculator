#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		int num_func, num_func1, num_int;
		char num_char[20], num_char2[20];
		printf("Выберите функцию:\n");
		printf("1) Перевод целых положительных десятичных чисел в римские числа и обратно.\n");
		printf("2) Выполнение арифметических действий(сложение, вычитание, умножение, деление) для римских чисел.\n");
		printf("3) Выход из калькулятора.\n");
		scanf("%d", &num_func);
		switch (num_func) {
		case 1:
			printf("Выберите действие:\n");
			printf("1) Перевод целых положительных десятичных чисел в римские числа.\n");
			printf("2) Перевод положительных римских чисел в десятичные числа.\n");
			scanf("%d", &num_func1);
			switch (num_func1) {
			case 1:
				do {
					printf("Введите число в диапозоне от 1 до 3999: ");
					scanf("%d", &num_int);
					if ((num_int < 1) || (num_int > 3999)) printf("Ошибка ввода, попробуйте еще раз.\n");
					else break;
				} while (1);
				printf("Римское число: %s\n", convertArabNum(num_int));
				break;
			case 2:
				do {
					printf("Введите римское число: ");
					scanf("%s", &num_char);
					if (!checkRomeNum(num_char)) printf("Ошибка ввода, попробуйте еще раз.\n");
					else break;
				} while (1);
				printf("Десятичное число: %d\n", convertRomeNum(num_char));
				break;
			default: printf("Такой функции не существует.\n"); break;
			}
			break;
		case 2:
			do {
				printf("Введите 1 римское число: ");
				scanf("%s", &num_char);
				if (!checkRomeNum(num_char)) {
					printf("Ошибка ввода, попробуйте еще раз.\n");
					continue;
				}
				printf("Введите 2 римское число: ");
				scanf("%s", &num_char2);
				if (!checkRomeNum(num_char2)) {
					printf("Ошибка ввода, попробуйте еще раз.\n");
					continue;
				}
				else break;
			} while (1);
			printf("Выберите арифметическое действие: \n");
			printf("1) Сложение\n");
			printf("2) Вычитание\n");
			printf("3) Умножение\n");
			printf("4) Деление\n");
			scanf("%d", &num_func1);
			switch (num_func1) {
			case 1: sumRomeNum(num_char, num_char2); break;
			case 2: difrRomeNum(num_char, num_char2); break;
			case 3: multRomeNum(num_char, num_char2); break;
			case 4: divRomeNum(num_char, num_char2); break;
			default: printf("Такой функции не существует\n"); break;
			}
			break;
		case 3:  exit(1); break;
		default: printf("Такой функции не существует.\n"); continue;
		}
	} while (1);
}
