
//В одномерном массиве, состоящем из n элементов, вычислить: 1)макс эл-т массива
//2)сумму эл-тов расположенных до последнего положительного эл-та.
//3)сжать массив удалив эл-ты в интервале (а,б) и поместив их в конец массива
#include <stdafx.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <conio.h>
 
using std::cout;
using std::cin;
using std::endl;
int main()
{

	float max, sum, a, b;
	int N;

	printf_s("VVEDITE RAZMER MASSIVA\n");
	scanf_s("%i", &N);
	float *arr = new float[N];

	printf_s("VVEDITE, a, b\n");
	scanf_s("%f%f", &a, &b);


	// Заполняем массив
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 20 - 10;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	//находим максимальный эл-т
	max = arr[0];
	for (int i = 0; i < N; i++)if (arr[i] > max) max = arr[i];
	printf_s("\nmax= %f\n", max);


	//находим сумму
	int n = 0;
	sum = 0;
	while (arr[n] > 0 && n < N) {
		sum = sum + arr[n];
		n++;
	}
	printf("sum= %f\n", sum);



	//смещение эл-тов
	int k = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (fabs(arr[i]) >= a && fabs(arr[i]) <= b) {
			for (int j = i; j < N - 1 - k; j++) {
				float h = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = h;
			}
			k++;
		}
	}

	// замена нулями - МОЙ АЛГОРИТМ // *************** не нужно
	//for (int i = 0; i < N; i++)
	//	if (fabs(arr[i]) >= a && fabs(arr[i]) <= b) k++;


	for (int i = 0; i <= k; i++)
		arr[N - i] = 0;

	//вывод массива
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	_getch();
	//system ("pause");
	return 0;
}

