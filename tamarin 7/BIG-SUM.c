#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void sum(char *a, char *b,char *c) {
	

	int len1, len2, temp;

	bool cond = false;

	len1 = strlen(a);
	len2 = strlen(b);
	if (len2 > len1) {
		sum(b, a, c);
		return;
	}
	c[len1 + 1] = '\0';
	for (int n = len1 - 1, m = len2 - 1; n >= 0; n--, m--) {
		if (m >= 0) {
			temp = a[n] + b[m] - '0' * 2;
			if (cond){
				temp += 1;
			cond = false;
			}
			if (temp < 10) {
				c[n + 1] = temp + '0';
			}
			else {
				cond = true;
				temp -= 10;
				c[n + 1] = temp + '0';
			}
		}
		else {
			if (cond) {
				temp = a[n] + 1 - '0';
				cond = false;
				if (temp > 9) {
					cond = true;
					temp -= 10;
					
				}
				c[n + 1] = temp + '0';

			}
			else {
				c[n + 1] = a[n];
			}
			 
		}
	}
	if (cond)c[0] = 1+'0';
	else {
		for (int k = 0; k < len1; k++) {
			c[k] = c[k + 1];
			
		}
		c[len1] = '\0';
	}
	
	return;
}

int main() {
	//char firstnum[80], secondnum[80],c[90];
	char* firstnum = (char*)malloc(sizeof(char) * 80);
	char* secondnum = (char*)malloc(sizeof(char) * 80);
	char* c = (char*)malloc(sizeof(char) * 90);

	scanf("%s\n%s", firstnum, secondnum);
	

	sum(firstnum, secondnum,c);
	printf("%s", c);


	return 0;
}
