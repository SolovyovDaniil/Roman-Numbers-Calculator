#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>

char* convertArabNum(int num) {
	const char* arr_rome_num[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int arr_arab_num[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 }, k = 0;
	char rome_num[20] = "", * rome_num2;
	rome_num2 = (char*)malloc(20 * sizeof(char));
	do {
		if (arr_arab_num[k] <= num) {
			num -= arr_arab_num[k];
			strcat(rome_num, arr_rome_num[k]);
		}
		else {
			k++;
		}
	} while (k < 13);
	return strcpy(rome_num2, rome_num);
}

int romeNum(char ch) {
	char arr_rome_num[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int arr_arab_num[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	for (int i = 0; i < 7; i++) {
		if (ch == arr_rome_num[i]) {
			return arr_arab_num[i];
		}
	}
}

int convertRomeNum(const char* num) {
	int arab_num = 0;
	for (int i = 0; i < strlen(num) - 1; i++) {
		if (romeNum(num[i]) < romeNum(num[i + 1])) arab_num -= romeNum(num[i]);
		else arab_num += romeNum(num[i]);
	}
	return arab_num + romeNum(num[strlen(num) - 1]);
}

bool checkRomeNum(const char* num) {
	if (strspn(num, "IVXLCDM") != strlen(num)) return FALSE;
	if (strcmp(convertArabNum(convertRomeNum(num)), num) != 0) return FALSE;
	return TRUE;
}

void sumRomeNum(char* num_char, char* num_char2) {
	double sum = convertRomeNum(num_char) + convertRomeNum(num_char2);
	if (sum > 3999) {
		printf("Сумма должна быть меньше 4000\n");
		return;
	}
	printf("Сумма двух римских чисел: %.0lf, %s\n", sum, convertArabNum(sum));
}

void difrRomeNum(char* num_char, char* num_char2) {
	double sum = convertRomeNum(num_char) - convertRomeNum(num_char2);
	if (sum <= 0) {
		printf("Первое число должно быть больше, чем второе.\n");
		return;
	}
	printf("Разность двух римских чисел: %.0lf, %s\n", sum, convertArabNum(sum));
}

void multRomeNum(char* num_char, char* num_char2) {
	double sum = convertRomeNum(num_char) * convertRomeNum(num_char2);
	if (sum > 3999) {
		printf("Произведение должно быть меньше 4000\n");
		return;
	}
	printf("Произведение двух римских чисел: %.0lf, %s\n", sum, convertArabNum(sum));
}

void divRomeNum(char* num_char, char* num_char2) {
	if (convertRomeNum(num_char) % convertRomeNum(num_char2) != 0) {
		printf("Второе число должно быть делителем первого.\n");
		return;
	}
	double sum = double(convertRomeNum(num_char)) / convertRomeNum(num_char2);
	printf("Деление двух римских чисел: %.0lf, %s\n", sum, convertArabNum(sum));
}