#include <stdio.h>
#include <conio.h>
#include <locale>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n;
	int arr[10];

	printf("Введите количество элементов массива: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("\n");
	printf("Массив: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	//Поиск минимального числа по индексу из массива
	int minIndex = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}

	//Поиск максимального числа по индексу из массива
	int maxIndex = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[maxIndex]) {
			maxIndex = i;
		}
	}
	//printf("%d", maxIndex);

	printf("\n");

	int start = min(minIndex, maxIndex);
	int end = max(minIndex, maxIndex);

	printf("Четные элементы массива между мин и макс: ");
	for (int i = start + 1; i < end; i++) {
		//arr[i] = 0;
		if (arr[i] % 2 == 0) {
			printf("%d ", arr[i]);
		}
	}
	
	printf("\n");

	_getch();
	return 0;
}