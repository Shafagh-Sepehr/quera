#include <stdio.h>
//include <math.h>
#pragma warning(disable:4996)

int main() {
    int i;
    char kalame1[60], kalame2[60],firstsfirst,lastslast;
    scanf("%s\n%s", kalame1, kalame2);


        firstsfirst = kalame1[0];
        for (i = 0; kalame2[i] != '\0'; i++);
        lastslast = kalame2[i - 1];
    (lastslast == firstsfirst) ? printf("YES") : printf("NO");
    return 0;
}
