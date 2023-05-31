#include <iostream>
#include <stdio.h>
#include <locale>
#include <conio.h>

int* InputArray(int* size)
{
	int* arr;
	int n;
	FILE* f;
	fopen_s(&f, "C:\\TEMP\\int8.txt", "rt");
	fscanf_s(f, "%d", &n);
	*size = n;
	arr = (int*)malloc(n * sizeof(int)); // динамическая память
	for (int i = 0; i < *size; i++)
	{
		fscanf_s(f, "%d", &arr[i]);
	}
	fclose(f);
	return arr;
}

void UpdateArrayMin(int* arr, int n, int* k)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	*k = min;
}

void UpdateArrayMax(int* arr, int n, int* x)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	*x = max;
}

void OutputArray(int min, int max)
{
	FILE* f;
	fopen_s(&f, "C:\\TEMP\\out8.txt", "wt");
	fprintf(f, "Минимальный элемент массива - %d", min);
	printf("Минимальный элемент массива - %d\n", min);
	fprintf(f, "\n");
	fprintf(f, "Максимальный элемент массива - %d", max);
	printf( "Максимальный элемент массива - %d", max);
	fclose(f);
}


int main(void)
{  
	setlocale(LC_ALL, "Russian");
	int* a; // создаем указатель на массив
	int min, max;
	int n; // создаем переменную для кол-ва элементов массива
	a = InputArray(&n);
	UpdateArrayMin(a, n, &min);
	UpdateArrayMax(a, n, &max);
	OutputArray(min, max);
	free(a); // освободить динамическую память
	_getch();
	return 0;
}