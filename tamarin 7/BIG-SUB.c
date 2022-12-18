#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void sub(char *a, char *b, char *c) {


	int len1, len2, temp;

	bool cond = false;

	len1 = strlen(a);
	len2 = strlen(b);
	if (len2 > len1) {
		printf("-");
		sub(b, a, c);
		return;
	}
	if (len2 == len1) {
		for (int p = 0; p < len1; p++) {
			if (a[p] == b[p]) {
				continue;
			}
			else if (a[p] < b[p]) {
				printf("-");
				sub(b, a, c);
				return;
			}
			else 
				break;

		}

	}
	c[len1] = '\0';
	for (int n = len1 - 1, m = len2 - 1; n >= 0; n--, m--) {
		if (m >= 0) {
			temp = a[n] - b[m] ;
			if (cond){
				temp -= 1;
			cond = false;
			}
			if (temp >= 0) {
				c[n] = temp + '0';
			}
			else {
				cond = true;
				temp += 10;
				c[n] = temp + '0';
			}
		}
		else {
			if (cond) {
				temp = a[n] - 1 - '0';
				cond = false;
				if (temp < 0) {
					cond = true;
					temp += 10;

				}
				c[n] = temp + '0';

			}
			else {
				c[n] = a[n];
			}

		}
	}
	//if (cond)c[0] = 1 + '0';
	//else {
		for (int k = 0; k < len1; k++) {
			c[k] = c[k];
		}
		c[len1] = '\0';
	//}


	while (c[0]-'0'==0) {
		for (int k = 0; k < len1; k++) {
			c[k] = c[k + 1];

		}
	}
	return;
}

int main() {
	//char firstnum[80], secondnum[80],c[90];
	char* firstnum = (char*)malloc(sizeof(char) * 100);
	char* secondnum = (char*)malloc(sizeof(char) * 100);
	char* c = (char*)malloc(sizeof(char) * 100);

	scanf("%s\n%s", firstnum, secondnum);
	if (!strcmp(firstnum, secondnum)) {
		printf("0");
		return 0;
	}

	sub(firstnum, secondnum, c);
	printf("%s", c);

	return 0;
}
