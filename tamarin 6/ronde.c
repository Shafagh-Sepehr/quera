#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#pragma warning(disable:4996)

bool tekrar4(char num[]) {
	int ctr;
	for (int des = 0; des < 10;des++) {
		ctr = 0;
		for (int index = 0; index < 8; index++) {
			if (num[index] == des + '0') 
				ctr++;
		}
		if (ctr >= 4) return true;
	}
	return false;
}

bool motavali3(char num[]) {
	int ctr=0;
	for (int index = 1; index < 8; index++) {
		if (num[index] == num[index - 1])
			ctr++;
		else
			ctr = 0;
		if (ctr >= 2) return true;
	}
	return false;
}

bool palindrom(char num[]) {
	if (num[0] == num[7] && num[1] == num[6] && num[2] == num[5] && num[3] == num[4])
		return true;
	return false;
	}

int main() {

	int n;
	char num[100],gar;
	scanf("%d", &n);
	if (n<1) return 0;
	gar = getchar();
	while (n--) {
		gets(num);
		
		if (tekrar4(num) || palindrom(num) || motavali3(num))
			printf("Ronde!");
		else
			printf("Rond Nist");
		if (n) printf("\n");
			
}

	return 0;
}
