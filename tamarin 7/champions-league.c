#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int gNum, treshHold,*arr,ctr=0;
	scanf("%d %d",&gNum,&treshHold);
	arr = (int*)malloc(200* sizeof(int));

	for (int i = 0; i < gNum; i++) {
		scanf("%d", arr + i);
	}
	for (int i = 0; i < gNum; i++) {
		if (*(arr + i) >= *(arr + treshHold-1) && *(arr + i)!=0)
			ctr++;
	}
	printf("%d\n", ctr);
	return 0;
}
