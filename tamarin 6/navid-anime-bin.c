#include <stdio.h>
#include <string.h>
//include <math.h>
#pragma warning(disable:4996)
char uppercase(char c) {
    if (c > 96 && c<=122)
         c -= 32;
       return c;
}
char lowecase(char c) {
    if (c <= 90 && c>=65)
        c += 32;
    return c;
}

int main() {
    int n;
    char esm[1005],gar;
    scanf("%d", &n);
    if (n == 0) return 0;
    gar = getchar();
    for (int i = 0; i<n; i++) {

        gets(esm);
    esm[0] = uppercase(esm[0]);

    for (int k=1;esm[k]!='\0';k++) {
        if (esm[k] == ' ') {
            esm[k + 1] = uppercase(esm[k + 1]);
            k++;
        }
        else
        esm[k] = lowecase(esm[k]);

    }
    if(i==n-1)
        printf("%s", esm);
    else
        printf("%s\n", esm);
    }

   

    return 0;
}
