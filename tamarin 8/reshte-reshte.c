#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

int checkcase(char *strn,char *str2n) {
	int len, len2;
	 len = strlen(strn);
	 len2 = strlen(str2n);
	if (len != len2) return 0;


	char *str = (char*)calloc((len + 5) , sizeof(char));
	char *str2 = (char*)calloc((len2 + 5) , sizeof(char));
	strcpy(str, strn);
	strcpy(str2, str2n);


	for (int i = 0; i < len; i++) {
		str[i]=tolower(strn[i]);
	}
	for (int i = 0; i < len; i++) {
		str2[i]=tolower(str2n[i]);
	}

	if (strcmp(str, str2) == 0)
	{
		free(str);
		free(str2);
		return 1;
	}

	free(str);
	free(str2);
	return 0;
	
}
int comp1(char* str, char* str2) {
	int len = strlen(str);
	int len2 = strlen(str2);
	int ctr = 0;
	if (len != len2)
		return 0;
	for (int i = 0; i <len ;i++) {
		if (str[i] != str2[i]){
			ctr++;
		if (ctr > 1) 
			return 0;
		}
	}
	return 1;
}

int comp2(char* strn, char* str2n) {


	int len = strlen(strn);
	int len2 = strlen(str2n);
	int ctr = 0;
	if (len == len2 || len - len2 != 1 && len - len2 != -1)
		return 0;

	char* str = (char*)calloc((len + 5) , sizeof(char));
	char* str2 = (char*)calloc((len2 + 5) , sizeof(char));
	strcpy(str, strn);
	strcpy(str2, str2n);
	if (len > len2) {
		if (len2 == 1 && len == 2) {
			if (str2[0] == str[0])
				return 1;
			else if (str2[0] == str[1])
				return 1;
			else
				return 0;
		}
		for (int i = 0; i < len; i++) {
			if (str[i] != str2[i]){
				for (; i < len; i++) {
					if (str[i+1] != str2[i])
						return 0;
				}
				return 1;
			}
		}



	}
	else if (len < len2) {
		if (len == 1 && len2 == 2) {
			if (str[0] == str2[0])
				return 1;
			else if (str[0] == str2[1])
				return 1;
			else
				return 0;
		}
		for (int i = 0; i < len2; i++) {
			if (str[i] != str2[i]) {
				for (; i < len2; i++) {
					if (str[i] != str2[i+1])
						return 0;
				}
				return 1;
			}
		}



	}
	free(str);
	free(str2);

	return 1;
}

int main() {
	int n,k,size;
	char gar;
	char* buffer = (char*)calloc(200 , sizeof(char));
	scanf("%d %d", &n,&k);
	scanf("%c", &gar);
	char** N;
	char** K;
	N = (char**)calloc(n+3 , sizeof(char*));
	K = (char**)calloc(k+3 , sizeof(char*));

	for (int i = 0; i < n; i++){
		scanf("%s", buffer);
		 size = strlen(buffer);
		 N[i] = (char*)malloc((size + 5) * sizeof(char));
		strcpy(N[i], buffer);
	}

	for (int i = 0; i < k; i++){
		scanf("%s", buffer);
		size = strlen(buffer);
		K[i] = (char*)malloc((size + 5) * sizeof(char));
		strcpy(K[i], buffer);
	}
	free(buffer);
	int ko=0;
	int *arr=(int*)calloc(100,sizeof(int));
	for (int kp = 0; kp < k; kp++) {
			int tedadMoshabeh=0;
		for (int np = 0; np < n; np++) {
			
			if (strcmp(K[kp], N[np])==0 || comp1(K[kp], N[np]) || comp2(K[kp], N[np]) || checkcase(K[kp], N[np]))
				arr[ko]++;
			
		}ko++;
		free(K[kp]);
		
		//printf("\n");

	}
	for (int i = 0; i < ko; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
