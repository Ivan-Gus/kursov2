#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_DEPRECATE

double f1(double x) {
	return (tan(x * x) - 1) / x;
}

double f2(double x) {
	return (x * exp(-x / 2)) / log(2 + x * x);
}

double f3(double x) {
	return pow(1 + x * x * x, 0.25);
}


// Основная функция вычисления f(x)
double n_f(double x) {
	if (x < -2) {
		return f1(x);
	}
	else if (x >= -2 & x < 3) {
		return f2(x);
	}
	else if (x >= 3) {
		return f3(x);
	}
	else {
		return NAN; // Неопределено
	}
}

double proizvod(double x, double h);
double find_Max(double start, double end);
double find_Min(double start, double end);
double find_x_y(double Y, double tochn, double start, double end);

int main() {
	setlocale(LC_CTYPE, "RUS");
	int c;
	double x,toch;
	double start, shag,y,end;
	int count;
	double prov,res;
	
	double h = 1e-6;
	do {
		printf("Кусочная функция\n\n");
		printf("1. Значение функции в точке \n2. Таблица значений \n3. Поиск минимума/максимума \n4. Поиск X по Y \n5. Производная в точке \n0. Выход \n");
		printf("Введите команду: \n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("Введите x: ");
			scanf("%lf", &x);
			printf("f(%.2f) = %.6f\n", x, n_f(x));
			break;
		case 2:
			printf("Введите начало интервала: ");
			scanf("%lf", &start);
			printf("Введите шаг: ");
			scanf("%lf", &shag);
			printf("Количество отсчетов: ");
			scanf("%d", &count);
			printf("\n===============================\n");
			printf("|  Таблица значений функции    |\n");
			printf("\n|==============================|\n");
			printf("| x | f(x) | \n");
			printf("\n|==============================|\n");
			for (int i = 0; i < count; i++) {
				y = n_f(start);
				printf("| %10.6f  | %12.8f |\n", start, y);
				printf("===============================\n");
				start += shag;
			}


			break;
		case 3:
			printf("Введите начало интервала: ");
			scanf("%lf", &start);
			printf("Введите конец интервала: ");
			scanf("%lf", &end);
			printf("Max в точке %.5lf\n", find_Max(start, end));
			printf("Min в точке %.5lf\n", find_Min(start, end));
			break;
		case 4:
			printf("Введите Y: ");
			scanf("%lf", &y);
			printf("Введите точность поиска: \n");
			scanf("%lf", &toch);
			res = find_x_y(y, toch, -1000, 1000);
			printf("Результат x = % .5f\n", res);

			break;
		case 5:
			printf("Введите x: \n");
			scanf("%lf", &x);
			prov = proizvod(x, h);
			printf("f'(%.6f) = %.6f\n", x, prov);
			break;
		}
	} while (c != 0); 
	





	return 0;
}

double find_x_y(double Y, double tochn, double start, double end) {
	double x, fx, best_x = start;
	double min = fabs(n_f(start) - Y);
	for (x = start; x <= end; x += 0.001) {
		fx = n_f(x);
		double diff = fabs(fx - Y);
		if (diff < min) {
			min = diff;
			best_x = x;
		}
		
	}
	return best_x;
}

double find_Min(double start, double end) {
	if (start >= end) {
		printf("Ошибка: start должен быть меньше end\n");
		return 0.0;
	}

	double min = n_f(start);
	double y;

	while (start < end) {
		y = n_f(start);
		if (min > y) {
			min = y;
		}
		start += 0.001;
	}
	return min;
}
double find_Max(double start, double end) {
	if (start >= end) {
		printf("Ошибка: start должен быть меньше end\n");
		return 0.0;
	}

	double max = n_f(start);
	double y;

	while (start < end) {
		y = n_f(start);
		if (max < y) {
			max = y;
		}
		start += 0.001;
	}
	return max;
}

double proizvod(double x, double h) {
	
	return (n_f(x + h) - n_f(x)) / h;
}