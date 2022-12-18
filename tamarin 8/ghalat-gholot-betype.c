#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)
int gap;

void remchar(char* str, int index) {
	int len = strlen(str);
	for (int i = index; i < len; i++) {
		str[i] = str[i + 1];
	}
	return;
}

void mainfun(char* fin, char* str) {
	int len = strlen(str);
	

	for (int i=0,k=0; ;i++) {
		if (str[i] == '=') {
			if (k > 0)
				k--;

		}
		else if (str[i] == '\0'){
			fin[k] = '\0';
			return;
		}
		else {
			fin[k] = str[i];
			k++;
		}


	}

}

int main() {
	char* str = (char*)malloc(100005 * sizeof(char));
	char* fin = (char*)malloc(100005 * sizeof(char));
	scanf("%s", str);

	mainfun(fin,str);
	printf("%s", fin);




	return 0;
}
