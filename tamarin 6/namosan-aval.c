#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#pragma warning(disable:4996)

bool avalsanj(int x) {
	if (x == 1)return false;
		for (int i = 2; i <= x / 2; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
int avalbadi(int des) {
	if (des == 2)return 3;
	des++;
		for (int i = 2; i <= des / 2; i++) {
			if (des % i == 0) {
				des++; i = 1;
			}
		}
		return des;
}


int main() {
	int n,andisNamosanAval,andisAval=2,aval=3,ctr=0;
	scanf("%d", &n);

	for (int i=0;i<n;i++) {
		andisAval = 2;
		aval = 3;
		ctr = 0;
		scanf("%d", &andisNamosanAval);
		while(1){
			if (avalsanj(andisAval)) {
				ctr++;
			}
			if (ctr == andisNamosanAval){
				if (i == n - 1)
				{
					printf("%d", aval); break;
				}
				else
				{
					printf("%d\n", aval); break;
				}
										}
			else{
				aval = avalbadi(aval);
				andisAval++;
			}
		}
	}

	return 0;
}
