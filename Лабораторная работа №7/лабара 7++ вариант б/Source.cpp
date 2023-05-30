#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale>


int InputArray(int arr[])//int bu butun son
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);//scanf bu scaner/qaladi
	}
	return n;
}


void OutputArray(int arr[], int n) //output chiqish array qatormassiv
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int MinArray(int arr[], int n)
{
	int b = 0;
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			b = i;
		}

	}

	return b, min;
}

int MaxArray(int arr[], int n)
{
	int m = 0;
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			m = i;
		}

	}

	return m, max;
}

int ChetArray(int arr[], int n)
{
	int b = MinArray(arr, n);
	int m = MaxArray(arr, n);
	for (int i = 0; i < n; i++)
	{
		if ((arr[2])|(i > b && i < m) | (i < b && i > m) && (arr[i] % 2 == 0))

			printf("%d ", arr[i]);
	}
	return 0;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int a[10];
	printf("Введите количество элементов массива:\n");
	n = InputArray(a);
	printf("Ваш массив: \n");
	OutputArray(a, n);
	printf("минимальный элемент ");
	int min = MinArray(a, n);
	printf("%d ", min);
	printf("Четные элементы ");
	ChetArray(a, n);
	printf("максимальный элемент ");
	int max = MaxArray(a, n);
	printf("%d ", max);
	_getch();
}