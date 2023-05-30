#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()//void bu bushliq
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	int arr[10];

	InputArray(&n, arr);
	return 0;
}
void SignedNumber(int* size, int* array)//signed bu imzolangan
{
	for (int i = 0; i < *size; i++)
	{
		if (array[i] % 2 == 0)
		{
			array[i] *= -1;
		}
	}
	return;
}

void OutputArray(int size, int array[])//output chiqish degan mano
{
	printf("¬аш массив: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return;
}

void InputArray(int* size, int array[])
{
	printf("\n¬ведите количество элементов массива: ");
	scanf_s("%d/n", size);//size bu razmer
	for (int i = 0; i < *size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	printf("\n");
	SignedNumber(size, array);
	OutputArray(*size, array);
	return;
}
