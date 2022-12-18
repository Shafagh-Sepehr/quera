#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int *f(int n) {
    int *arr;
    arr = (int*)malloc(1000* sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
    return arr;
}

int main() {
    int n;
    scanf("%d", &n);
    int* b = f(n);

    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
