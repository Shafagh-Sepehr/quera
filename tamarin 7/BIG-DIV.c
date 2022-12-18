#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define cSIZE 160

int mypow(unsigned long long int a, unsigned long long int b) {
	if (b == 1) return a;
	return a * mypow(a, b - 1);
}

/*
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
*/






void sum(char* a, char* b, char* c) {


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
			if (cond) {
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
	if (cond)c[0] = 1 + '0';
	else {
		for (int k = 0; k < len1; k++) {
			c[k] = c[k + 1];

		}
		c[len1] = '\0';
	}

	return;
}

void mul(char* a, char* b, char* c) {
	char* finaltemp = (char*)malloc(sizeof(char) * 100);
	strcpy(finaltemp, c);
	char* tempstr;
	char* tempstrtemp = (char*)calloc(cSIZE, sizeof(char));
	char* cp;

	tempstrtemp[0] = '0';
	tempstrtemp[0] = '\0';
	int len1, len2, temp, cIndex = cSIZE - 2, ctr0 = 0;
	short strg = 0;

	len1 = strlen(a);
	len2 = strlen(b);
	if (len2 > len1) {
		mul(b, a, c);
		return;
	}


	for (int n = len2 - 1; n >= 0; n--, ctr0++) {//b[n]

		cIndex = cSIZE - 2;
		cp = (char*)calloc(cSIZE, sizeof(char));
		tempstr = (char*)calloc(cSIZE + 1, sizeof(char));
		if (ctr0)strcpy(cp, tempstrtemp);


		for (int m = len1 - 1; m >= 0; m--) {//a[m]
			temp = (b[n] - '0') * (a[m] - '0');

			if (strg) { temp += strg; strg = 0; }

			if (temp > 9) {
				tempstr[cIndex] = temp % 10 + '0';
				cIndex--;
				strg = temp / 10;
			}
			else {
				tempstr[cIndex] = temp + '0';
				cIndex--;
			}

		}
		if (strg) { tempstr[cIndex] = strg + '0'; strg = 0; cIndex--; }
		while (tempstr[0] == '\0') {
			for (int k = 0; k < cSIZE; k++) {
				tempstr[k] = tempstr[k + 1];


			}
		}


		{
			int l = strlen(tempstr);
			tempstr[l + ctr0] = '\0';

			for (int p = 0; p < ctr0; p++) {

				tempstr[l + p] = '0';
				//printf(tempstr);
				//printf("\n");
			}
		}



		sum(tempstr, cp, tempstrtemp);
		free(tempstr);
		free(cp);
	}
	//printf("%s", tempstrtemp);
	strcpy(c, tempstrtemp);
	free(finaltemp);
	return;
}
void khikhi(char* khi, int a) {
	khi[a - 1] = khi[a];

}

void DIV(char* a, char* b, char* fin) {
	char* save = (char*)malloc(sizeof(char) * 100);
	char* fi = (char*)malloc(sizeof(char) * 100);
	char* ficop = (char*)malloc(sizeof(char) * 100);
	char* ofasele = (char*)malloc(sizeof(char) * 100);
	char* kh1 = (char*)malloc(sizeof(char) * 100);
	char* kharj = (char*)malloc(sizeof(char) * 100);
	char* kharjsave = (char*)malloc(sizeof(char) * 100);
	int len1, len2, temp ;
	unsigned long long int kharejGhesmat = 0, u = 0, kh = 1, ukh;
	bool cond = true;
	kharj[0] = '0';
	kharj[1] = '\0';
	ofasele[0] = '1';
	ofasele[1] = '\0';
	kh1[0] = '1';
	kh1[1] = '\0';
	strcpy(fin, b);
	strcpy(fi, b);
	

	len1 = strlen(a);
	len2 = strlen(b);
	if (len2 > len1) {
		printf("0");
		return;
	}
	int o = len1 - len2 - 1;

	if (o>0) {
		
		kh = mypow(10, o+1);
		for (int i = 0; i < o+1; i++) {
			kh1[i + 1] = '0';
			kh1[i + 2] = '\0';
			ukh = i + 2;
		}
		for (int i = 0;i < o; i++) {
			ofasele[i + 1] = '0';
			ofasele[i + 2] = '\0';
			u = i + 2;
		}



		//mul(b, ofasele, fin);
	}
	else {
		kh = 1;
	}





		strcpy(ficop, fin);
		bool yj = true;

		
		while (u > 0 || yj) {
			
			yj = false;
			if (u >= 1) {
				ofasele[u] = '\0';
				u--;
				kh /= 10;
				khikhi(kh1, ukh); ukh--;
				mul(b, ofasele, ficop);
			}



			while (cond) {



				strcpy(save, fin);
				sum(ficop, fi, fin);
				strcpy(fi, fin);

				len2 = strlen(fin);
				//printf("%s\n",fin);

				if (len2 > len1) {
					cond = false;
				}
				if (len2 == len1) {
					for (int p = 0; p < len1; p++) {
						if (a[p] == fin[p]) {
							continue;
						}
						else if (a[p] < fin[p]){
							cond = false;
							break;
							}
						else
							break;
					}

				}
				kharejGhesmat += kh;
				strcpy(kharjsave, kharj);
				sum(kharj, kh1, kharj);
				
			}
			kharejGhesmat -= kh;
			strcpy(kharj, kharjsave);
			strcpy(fin, save);
			strcpy(fi, save);
			cond = true;

		}
			
			



		//	strcpy(fin, save);
		//	strcpy(fi, save);

	

	//cond = true;








	/*while (cond) {

		sum(b, fi, fin);
		strcpy(fi, fin);

		len2 = strlen(fin);


		if (len2 > len1) {
			cond = false;
		}
		if (len2 == len1) {
			for (int p = 0; p < len1; p++) {
				if (a[p] == fin[p]) {
					continue;
				}
				else if (a[p] < fin[p])
					cond = false;
				else
					break;
			}

		}
		kharejGhesmat++;


	}*/
		char* one = (char*)malloc(sizeof(char) * 3);
		one[0] = '1'; one[1] = '\0';
		sum(kharj, one, kharj);

		printf("%s\n", kharj);
	kharejGhesmat++;

	//printf("%llu\n", kharejGhesmat);

	return;
}


int main() {
	char* fin = (char*)malloc(100 * sizeof(char));
	char* firstnum = (char*)malloc(sizeof(char) * 100);
	char* secondnum = (char*)malloc(sizeof(char) * 100);


	scanf("%s\n%s", firstnum, secondnum);


	DIV(firstnum, secondnum, fin);



	return 0;
}
