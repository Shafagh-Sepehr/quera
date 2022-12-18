#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)


int main() {
	int l,r;
	scanf("%d%d", &l,&r);
	l--; r--;
	char *str=(char*)malloc(200005*sizeof(char));
	char* strtemp = (char*)malloc(200005 * sizeof(char));
	str[0] = '1';
	str[1] = '\0';
	for (int i = 0; i < 17; i++) {

		strcpy(strtemp, str);
		int len = strlen(strtemp);
		for (int j = 0; j < len; j++) {
			if (strtemp[j] == '0')
				strtemp[j] = '1';
			else
				strtemp[j] = '0';
		}
		strcat(str, strtemp);
	}

	for (int i = l; i <= r; i++) {
		printf("%c", str[i]);
	}



	return 0;
}
