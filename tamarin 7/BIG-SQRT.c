#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define cSIZE 250
#define normalStrSize 250
#define cap0 150



void sub(char* a, char* b, char* ch) {
	char* c = (char*)malloc(sizeof(char) * normalStrSize);
	if (!strcmp(a, b)) {
		c[0] = '0';
		c[1] = '\0';
		return;
	}

	int len1, len2, temp;

	bool cond = false;

	len1 = strlen(a);
	len2 = strlen(b);
	if (len2 > len1) {
		//printf("-");
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
			temp = a[n] - b[m];
			if (cond) {
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


	while (c[0] - '0' == 0) {
		for (int k = 0; k < len1; k++) {
			c[k] = c[k + 1];

		}
	}

	strcpy(ch, c);
	return;
}



int mypow(unsigned long long int a, unsigned long long int b) {
	if (b == 1) return a;
	return a * mypow(a, b - 1);
}




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
void mulsahih(char* a, char* b, char* c) {

	char* finaltemp = (char*)malloc(sizeof(char) * normalStrSize);
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
		mulsahih(b, a, c);
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

void mul(char* a, char* b, char* c) {
	char* ctemp = (char*)malloc(sizeof(char) * normalStrSize);
	strcpy(ctemp, a);

	int lenc = strlen(a);
	int point = 0;
	int sahih;
	for (int i = lenc - 1; i >= 0; i--, point++) {
		sahih = i;
		if (a[i] == '.')
			break;
		if (i == 0)
			point = -1;
	}

	if (point) {
		for (int i = sahih; ctemp[i] != '\0'; i++)
			ctemp[i] = ctemp[i + 1];
	}


	char* tempstr;
	char* tempstrtemp = (char*)calloc(cSIZE, sizeof(char));
	char* cp;

	tempstrtemp[0] = '0';
	tempstrtemp[1] = '\0';
	int len1, len2, temp, cIndex = cSIZE - 2, ctr0 = 0;
	short strg = 0;

	len1 = len2 = strlen(ctemp);



	for (int n = len2 - 1; n >= 0; n--, ctr0++) {//b[n]

		cIndex = cSIZE - 2;
		cp = (char*)calloc(cSIZE, sizeof(char));
		tempstr = (char*)calloc(cSIZE + 1, sizeof(char));
		if (ctr0)strcpy(cp, tempstrtemp);


		for (int m = len1 - 1; m >= 0; m--) {//a[m]
			temp = (ctemp[n] - '0') * (ctemp[m] - '0');

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

			}
		}



		sum(tempstr, cp, tempstrtemp);
		free(tempstr);
		free(cp);
	}
	//printf("%s", tempstrtemp);


	if (point) {
		point *= 2;
		int lencH = lenc = strlen(tempstrtemp);
		for (int i = 0; i <= point; i++) {
			tempstrtemp[lenc + 1] = tempstrtemp[lenc];
			lenc--;
		}
		tempstrtemp[lencH - point] = '.';
	}

	strcpy(c, tempstrtemp);

	return;
}

void khikhi(char* khi, int a) {
	khi[a - 1] = khi[a];

}

void DIVsahih(char* a, char* b, char* fint) {
	char* fin = (char*)malloc(sizeof(char) * normalStrSize);

	char* save = (char*)malloc(sizeof(char) * normalStrSize);
	char* fi = (char*)malloc(sizeof(char) * normalStrSize);
	char* ficop = (char*)malloc(sizeof(char) * normalStrSize);
	char* ofasele = (char*)malloc(sizeof(char) * normalStrSize);
	char* kh1 = (char*)malloc(sizeof(char) * normalStrSize);
	char* kharj = (char*)malloc(sizeof(char) * normalStrSize);
	char* kharjsave = (char*)malloc(sizeof(char) * normalStrSize);

	int len1, len2, temp;
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

	if (o > 0) {

		kh = mypow(10, o + 1);
		for (int i = 0; i < o + 1; i++) {
			kh1[i + 1] = '0';
			kh1[i + 2] = '\0';
			ukh = i + 2;
		}
		for (int i = 0; i < o; i++) {
			ofasele[i + 1] = '0';
			ofasele[i + 2] = '\0';
			u = i + 2;
		}




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
			mulsahih(b, ofasele, ficop);
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
					else if (a[p] < fin[p]) {
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


	char* one = (char*)malloc(sizeof(char) * 3);
	one[0] = '1'; one[1] = '\0';
	sum(kharj, one, kharj);

	//printf("%s\n", kharj);
	strcpy(fint, kharj);



	return;
}


void DIV(char* a, char* b, char* finans) {
	char* fin = (char*)malloc(normalStrSize * sizeof(char));
	char* save = (char*)malloc(sizeof(char) * normalStrSize);
	char* fi = (char*)malloc(sizeof(char) * normalStrSize);
	char* ficop = (char*)malloc(sizeof(char) * normalStrSize);
	char* ofasele = (char*)malloc(sizeof(char) * normalStrSize);
	char* kh1 = (char*)malloc(sizeof(char) * normalStrSize);
	char* kharj = (char*)malloc(sizeof(char) * 250);
	char* kharjsave = (char*)malloc(sizeof(char) * normalStrSize);


	int len1, len2, temp;
	unsigned long long int  u = 0, ukh;
	bool cond = true;
	kharj[0] = '0';
	kharj[1] = '\0';
	ofasele[0] = '1';
	ofasele[1] = '\0';
	kh1[0] = '1';
	kh1[1] = '\0';


	len1 = strlen(a);
	len2 = strlen(b);
	//len1 += cap0;

	for (int i = 0; i < cap0; i++) {
		a[len1 + i] = '0';
	}
	a[len1 + cap0] = '\0';
	len1 = strlen(a);

	strcpy(fin, b);
	strcpy(fi, b);



	int o = len1 - len2 - 1;

	if (o > 0) {


		for (int i = 0; i < o + 1; i++) {
			kh1[i + 1] = '0';
			kh1[i + 2] = '\0';
			ukh = i + 2;
		}

		for (int i = 0; i < o; i++) {
			ofasele[i + 1] = '0';
			ofasele[i + 2] = '\0';
			u = i + 2;
		}




	}






	strcpy(ficop, fin);
	bool yj = true;


	while (u > 0 || yj) {

		yj = false;
		if (u >= 1) {
			ofasele[u] = '\0';
			u--;

			khikhi(kh1, ukh); ukh--;
			mulsahih(b, ofasele, ficop);
		}



		while (cond) {



			strcpy(save, fin);
			sum(ficop, fi, fin);
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
					else if (a[p] < fin[p]) {
						cond = false;
						break;
					}
					else
						break;
				}

			}

			strcpy(kharjsave, kharj);
			sum(kharj, kh1, kharj);

		}


		strcpy(kharj, kharjsave);
		strcpy(fin, save);
		strcpy(fi, save);
		cond = true;

	}


	char* one = (char*)malloc(sizeof(char) * 3);
	one[0] = '1'; one[1] = '\0';
	sum(kharj, one, kharj);

	int lenkh = strlen(kharj);
	int marz;




	int countr = 0;





	for (int i = 0; i < cap0; i++) {
		if (kharj[lenkh - i - 1] == '0' && lenkh - i - 1 > 0)
			continue;



		else if (kharj[lenkh - i - 1] == '0' && lenkh - i - 1 <= 0) {

			printf("ridi dada");









		}


		else if (strlen(kharj) < cap0) {
			//sprintf(finans, "0.");
			{finans[countr] = '0'; countr++; finans[countr] = '.'; countr++; }

			int zero = cap0 - lenkh;//- 1
			for (int r = 0; r < zero; r++, countr++)
				// sprintf(finans, "0" );
			{
				finans[countr] = '0';
			}
			for (int r = 0; r < lenkh - i; r++, countr++)
			{
				//sprintf(finans, "%c", kharj[r]);

				finans[countr] = kharj[r];

			}
			finans[countr] = '\0';
			return;

		}
		else {
			marz = lenkh - i;
			int point = lenkh - cap0;
			for (int r = 0; r < point; r++, countr++) {
				//sprintf(finans, "%c", kharj[r]);
				finans[countr] = kharj[r];

			}
			if (!point) { finans[countr] = '0'; countr++; }
			/* printf(".");*/  finans[countr] = '.'; countr++;
			int had = marz;
			for (int r = lenkh - cap0 - 1; r < marz - 1; r++, countr++) {
				//sprintf(finans, "%c",kharj[r + 1] );
				finans[countr] = kharj[r + 1];
			}
			finans[countr] = '\0';
			return;
		}

	}




	for (int mmd = 0; mmd < lenkh - cap0; mmd++, countr++)
		//sprintf(finans, "%c",kharj[mmd] );
		finans[countr] = kharj[mmd];
	//free(fin);
	//free(save);
	//free(fi);
	//free(ficop);
	//free(ofasele);
	//free(kh1);
	//free(kharj);
	//free(kharjsave);
	finans[countr] = '\0';

	return;
}

void check_sqrt_ans(char*num,char*ans) {
	char* one = (char*)malloc(sizeof(char) * 3);
	one[0] = '1';
	one[1] = '\0';
	char* temp = (char*)malloc(sizeof(char) * normalStrSize);
	char* temp2 = (char*)malloc(sizeof(char) * normalStrSize);
	char* temp3 = (char*)malloc(sizeof(char) * normalStrSize);
	bool amaliat = false;
	mul(ans, ans, temp);
	int len_ans = strlen(temp);
	int len_num = strlen(num);
	sum(ans, one,temp2);
	mul(temp2, temp2, temp3);
	if (strcmp(temp3, num) == 0) {
		strcpy(ans, temp2);
		return;
	}
	




	if (len_ans < len_num)
		return;
	else if(len_ans==len_num) {
		for (int p = 0; p < len_ans; p++) {
			if (num[p] == temp[p]) {
				continue;
			}

			else {
				if(num[p] > temp[p])
					amaliat = false;
				else
					amaliat = true;
				break;
			}
		}
	}
	//else .....

	if (amaliat) {
		
		sub(ans, one, ans);
	}

}


void SQRT(char* num, char* ans) {

	//char* ans = (char*)malloc(sizeof(char) * normalStrSize);
	char* low = (char*)malloc(sizeof(char) * normalStrSize);
	char* high = (char*)malloc(sizeof(char) * normalStrSize);



	char* dow = (char*)malloc(sizeof(char) * 3);
	dow[0] = '2';
	dow[1] = '\0';

	char* one = (char*)malloc(sizeof(char) * 3);
	one[0] = '1';
	one[1] = '\0';

	low[0] = '1'; low[1] = '\0';

	DIVsahih(num, dow, high);
	sum(high, one, high);

	

	while (1) {
		char* tempfinalchack = (char*)malloc(sizeof(char) * normalStrSize);
		char* anscan = (char*)malloc(sizeof(char) * normalStrSize);
		char* mid = (char*)malloc(sizeof(char) * normalStrSize);
		char* temp = (char*)malloc(sizeof(char) * normalStrSize);
		sum(low, high, temp);
		DIVsahih(temp, dow, mid);
		mul(mid, mid, anscan);



		int len1 = strlen(num), len2 = strlen(anscan);
		int cond;

		if (len2 > len1) {
			cond = 1;
		}
		else if (len2 == len1) {
			for (int p = 0; p < len1; p++) {
				if (num[p] == anscan[p]) {
					continue;
				}
				else if (num[p] < anscan[p]) {
					cond = 1;
					break;
				}
				else {
					cond = -1;
					break;
				}
			}

		}
		else
			cond = -1;


		if (strcmp(anscan, num) == 0) {
			strcpy(ans, mid);
			//printf("%s", mid);
			return;
		}
		else if (cond == 1) {

			if (strcmp(low, high) == 0)
			{
				strcpy(ans, low);
				check_sqrt_ans(num, ans);
				return;
			}


			sum(low, one, tempfinalchack);
			int lenhigh = strlen(high);
			int lenfinal = strlen(tempfinalchack);
			bool isthesame = true;
			if (lenfinal == lenhigh) {
				for (int p = 0; p < lenhigh; p++) {
					if (high[p] == tempfinalchack[p]) {
						continue;
					}

					else {
						isthesame = false;
						break;
					}
				}
				if (isthesame) {
					//printf(mid);
					strcpy(ans, mid);
					check_sqrt_ans(num, ans);
					return;
				}
			}


			sub(mid, one, high);
		}
		else if (cond == -1) {

			if (strcmp(low, high) == 0)
			{
				strcpy(ans, low);
				check_sqrt_ans(num, ans);
				return;
			}

			sum(low, one, tempfinalchack);
			int lenhigh = strlen(high);
			int lenfinal = strlen(tempfinalchack);
			bool isthesame = true;
			if (lenfinal == lenhigh) {
				for (int p = 0; p < lenhigh; p++) {
					if (high[p] == tempfinalchack[p]) {
						continue;
					}

					else {
						isthesame = false;
						break;
					}
				}
				if (isthesame) {
					//printf(mid);
					strcpy(ans, mid);
					check_sqrt_ans(num, ans);
					return;
				}
			}

			sum(mid, one, low);
		}





		free(temp);
		free(mid);
		free(anscan);

	}

}






int main() {

	char* num1 = (char*)malloc(sizeof(char) * normalStrSize);
	char* num2 = (char*)malloc(sizeof(char) * normalStrSize);
	char* ans = (char*)malloc(sizeof(char) * normalStrSize);

	char* zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0';
	zero[1] = '\0';


	//scanf("%s\n%s", num1,num2);
	//suma(num1, num2, ans);
	//printf(ans);


	scanf("%s", num1);

	if (strcmp(zero, num1) == 0) {
		printf("0");
		return 0;
	}


	int len = strlen(num1);

	for (int i = 0; i < 22; i++) {
		num1[i + len] = '0';
		if (i == 21)
			num1[i + len + 1] = '\0';
	}

	SQRT(num1,ans);


	int len2 = strlen(ans);
	ans[len2 + 1] = '\0';
	for (int i = 0; i < 11; i++) {
		ans[len2 - i] = ans[len2 - i - 1];
	}
	ans[len2 - 11] = '.';

	len2 = strlen(ans);
	ans[len2 - 1] = '\0';

	len2 = strlen(ans);

	for (int i = 0; i <= 10; i++) {
		if (ans[len2-i-1] != '0') {
			ans[len2-i] = '\0';
			if (ans[len2 - i - 1] == '.') {
				ans[len2 - i - 1] = '\0';
			}
			break;
		}
	}






	printf("%s",ans);

	/*scanf("%s\n%s", firstnum, firstnum1);
	DIVsahih(firstnum,firstnum1,ans);
	printf(ans);*/



	return 0;
}
