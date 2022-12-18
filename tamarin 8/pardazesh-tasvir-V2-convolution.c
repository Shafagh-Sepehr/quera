#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)
void fillMatrix(int** matris, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matris[i][j]);
		}
	}

}

void doCernel(int** matris, int** final_matris, int** cernel , int Y, int X,int m) {
	int temp=0,cernelnum;
	int marz = m /2;
	for (int i =0, y=-marz; i <m ; i++,y++) {
		;
		for (int j =0,x = -marz ; j <m ; j++,x++) {
			temp+=matris[Y+y][X+x]*cernel[i][j];
			
		}
		
	}
	if (temp > 255)
		temp = 255;
	else if (temp < 0)
		temp = 0;

	final_matris[Y][X] = temp;
	return;
}


int main() {
	int n,m;
	scanf("%d", &n);
	int** matrix = (int**)malloc((n) * sizeof(int*));
	int** final_matrix = (int**)malloc((n) * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matrix[i]= (int*)malloc((n) * sizeof(int));
		final_matrix[i] = (int*)malloc((n) * sizeof(int));
	}
	fillMatrix(matrix, n);


	scanf("%d", &m);
	int** cernel = (int**)malloc((m) * sizeof(int*));
	for (int i = 0; i < m; i++) {
		cernel[i] = (int*)malloc((m) * sizeof(int));
	}
	fillMatrix(cernel, m);


	int marz = m / 2;
	for (int i = marz; i < n - marz; i++) {
		for (int j = marz; j < n - marz; j++) {
			doCernel(matrix, final_matrix,cernel, i, j,m);
		}
	}
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			if (i <marz || j <marz || i >=n-marz || j >= n - marz) {
				final_matrix[i][j] = 0;
			}
			printf((j == n - 1) ? "%d" : "%d ", final_matrix[i][j]);
			//printf("%d ", final_matrix[i][j]);
		}
		free(final_matrix[i]);
		printf((i == n - 1) ? "" : "\n");
		//printf("\n");
	}
	free(matrix);
	free(cernel);
	free(final_matrix);


	return 0;
}
