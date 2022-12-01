#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int main() {
    char matn[1000], ctr = 0, tedad = 1;
    scanf("%s", matn);
    for (int i = 0; matn[i] != '\0'; i++) {
        switch (matn[i])
        {
        case 'a':ctr++; break;
        case 'u':ctr++; break;
        case 'i':ctr++; break;
        case 'o':ctr++; break;
        case 'e':ctr++; break;

        default:

            break;
        }
    }
    tedad = tedad * pow(2, ctr);
    printf("%d", tedad);

    return 0;
}
