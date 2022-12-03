#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define SIZE 260
#pragma warning(disable:4996)
void Convert2Negative(int pic[SIZE][SIZE],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pic[i][j] = 255 - pic[i][j];
		}
	}
	return;
}
void PrintImage(int pic[SIZE][SIZE], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf((j==n-1)?"%d":"%d ", pic[i][j]);
		}
		printf((i == n - 1) ? "" : "\n");
	}
}

int main() {
	int n,pic[SIZE][SIZE];
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d",&pic[i][j]);
		}
	}
	Convert2Negative(pic, n);
	PrintImage(pic, n);

	return 0;
}
