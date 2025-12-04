#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_DEPRECATE



double* rand_generator(double* ptr_array, int n);
double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);


int main() {
	setlocale(LC_CTYPE, "RUS");
	double* ptr_array;
	int size;
	int k;
	printf("Введите размер массива - ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));

	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}

	full_elements(ptr_array, size);
	printf("Массив 1:\n");
	put_elements(ptr_array, size);
	printf("Массив 2:\n");
	calc_elements(ptr_array, size);
	put_elements(ptr_array, size);

	free(ptr_array);
	puts("Массив со случайными элементами");
	rand_generator(ptr_array, size);
	put_elements(ptr_array, size);

	puts("Введите номер элемента");
	scanf("%d", &k);


	return 0;
}

double F(double x) {
	return x * x - pow(cos(x + 1), 2);
}

double* full_elements(double* ptr_array, int n) {
	double g = 3;
	for (int i = 0; i < n; i++) {

		ptr_array[i] = F(g);
		g += 0.1;

	}
	return ptr_array;
}

int put_elements(double* ptr_array, int n) {
	int i = 0;
	while (i < n) {
		printf("array[%d] = %lf\n", i, *ptr_array++);
		i++;
	}
	return 1;
}

double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = ptr_array[i] / 10;

	}
	return ptr_array;
}

double* rand_generator(double* ptr_array, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		ptr_array[i]= ((double)rand() / RAND_MAX) * 2.0 - 1.0; // от -1 до 1 числа

	}
	return ptr_array;
}

int* delete_k(double* ptr_array, int size) { //Удаление двух максимальных элементов.
	/* ptr_arr - адрес массива
	   size - число элементов  */
	int max1 = 0;
	int max2 = 1;
	
	for (int i=2;i<size;i++){
		if (ptr_array[i] > max1) {
			max2 = max1;
			max1 = i;
		}
		else {
			if (ptr_array[i] > ptr_array[max2]) {
				max2 = i;
			}
		}
	}
	int n = size - 2;

	

}