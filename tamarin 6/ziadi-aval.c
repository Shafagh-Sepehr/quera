#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#pragma warning(disable:4996)

bool kheilifirst(int a) {
	for(;a;a/=10){
	switch (a%10)
	{
	case 0:return false;
	case 1:return false;
	case 4:return false;
	case 6:return false;
	case 8:return false;
	case 9:return false;

	default:
		break;
	}
  }
	return true;
}

int main() {
	bool first;
	int saqf,aval[10000],ziadiaval[10000],des=2,i=-1,p=-1;
	scanf("%d", &saqf);
	for(;des<saqf;des++){
		first = true;
	for (int i=2;i<=des/2;i++) {
		if (des % i == 0) {
			first = false;
			break; 
		}
	}
	if (first == true) {
		aval[++i] = des;
	}
}
	for (int k=0;k<=i; k++) {
		if (kheilifirst(aval[k])) {
			ziadiaval[++p] = aval[k];
		}
	}
	for (int i = 0; i <= p;i++) {
		printf("%d", ziadiaval[i]); if (i - p)printf(" ");
	}
	

	return 0;
}
