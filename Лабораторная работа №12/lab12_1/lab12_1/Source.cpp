#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
struct figure {
	int x;
	int y;
	int R;
	int W;
	int r;
	int g;
	int b;
};

int main() {
	FILE* f;
	int n, i;
	setlocale(LC_ALL, "Russian");
	fopen_s(&f,"C:\\TEMP\\struct.bin", "wb");
	printf("¬ведите количество кругов: ");
	scanf("%d", &n);
	fwrite(&n, sizeof(int), 1, f);
	for (i = 0; i < n; i++) {
		figure circle;
		printf("¬ведите x, y, R, w, r, g, b: ");
		scanf("%d%d%d%d%d%d%d", &circle.x, &circle.y, &circle.R, &circle.W, &circle.r, &circle.g, &circle.b);
		fwrite(&circle, sizeof(figure), 1, f);
	}
	fclose(f);
	return 0;
}
