#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)
#define N 9
void print_sod(int sod[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", sod[i][j]);
		}
		printf("\n");
	}
}
void get_sod(int sod[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &sod[i][j]);
		}
	}
}

int get_possible_numbers(int sod[N][N], int n_list[9], int* ctr, int i, int j) {
	bool cand[10] = { true,true, true, true, true, true, true, true, true,true };
	for (int k = 0; k < N; k++) {
		switch (sod[i][k]) {
		case 1:cand[1] = false; break;
		case 2:cand[2] = false; break;
		case 3:cand[3] = false; break;
		case 4:cand[4] = false; break;
		case 5:cand[5] = false; break;
		case 6:cand[6] = false; break;
		case 7:cand[7] = false; break;
		case 8:cand[8] = false; break;
		case 9:cand[9] = false; break;

		default:
			break;
		}

	}
	for (int k = 0; k < N; k++) {
		switch (sod[k][j]) {
		case 1:cand[1] = false; break;
		case 2:cand[2] = false; break;
		case 3:cand[3] = false; break;
		case 4:cand[4] = false; break;
		case 5:cand[5] = false; break;
		case 6:cand[6] = false; break;
		case 7:cand[7] = false; break;
		case 8:cand[8] = false; break;
		case 9:cand[9] = false; break;
		default:
			break;
		}
	}
	int i1, i2, j1, j2;
	if (i < 3) {
		i1 = 0;
		i2 = 3;
	}
	else if (i < 6) {
		i1 = 3;
		i2 = 6;
	}
	else {
		i1 = 6;
		i2 = 9;
	}

	if (j < 3) {
		j1 = 0;
		j2 = 3;
	}
	else if (j < 6) {
		j1 = 3;
		j2 = 6;
	}
	else {
		j1 = 6;
		j2 = 9;
	}
	for (int i = i1; i < i2; i++) {
		for (int j = j1; j < j2; j++) {
			switch (sod[i][j]) {
			case 1:cand[1] = false; break;
			case 2:cand[2] = false; break;
			case 3:cand[3] = false; break;
			case 4:cand[4] = false; break;
			case 5:cand[5] = false; break;
			case 6:cand[6] = false; break;
			case 7:cand[7] = false; break;
			case 8:cand[8] = false; break;
			case 9:cand[9] = false; break;
			default:
				break;
			}
		}
	}
	int ctr2 = 0; (*ctr) = 0;
	for (int i = 1; i < 10; i++) {
		if (cand[i]) {
			(*ctr)++;
			n_list[ctr2] = i;
			ctr2++;
		}
	}
	return ctr;
}

int solve_sod(int sod[N][N], int i, int j) {

	if (j == 9 && i == 8) {
		//print_sod(sod);
		return 1;
	}
	if (j >= N) {
		j = 0;
		i++;
	}
	int num_list[9], ctr;



	if (sod[i][j] == 0) {
		if (!get_possible_numbers(sod, num_list, &ctr, i, j)) {
			return 0;
		}

		for (int k = 0; k < ctr; k++) {
			sod[i][j] = num_list[k];
			if (solve_sod(sod, i, j + 1) == 1)
				return 1;
		}
		sod[i][j] = 0;
		return 0;
	}
	else {
		if (solve_sod(sod, i, j + 1) == 1)
			return 1;
		else
			return 0;
	}

}


int main() {
	int sod[N][N];
	get_sod(sod);
	solve_sod(sod, 0, 0);
	print_sod(sod);
	return 0;
}
