#include<stdio.h>
#include <crtdbg.h>
#include <iostream>
#include <corecrt_malloc.h>
int main()
{
	int m;
	int* arr;
	FILE* f;
	fopen_s(&f, "C:\\TEMP\\lab8.txt", "rt");
	fopen_s(&f, "C:\\TEMP\\out8.txt", "rt");
	if (f == NULL)
	{
		printf("file not found");
		return 0;
	}
	fscanf_s(f, "%d\n", &m);
	arr = (int*)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		fscanf_s(f, " %d ", &arr[i]);
	}

	return;

}