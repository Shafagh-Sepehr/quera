#include <stdio.h>
//include <math.h>
#pragma warning(disable:4996)

int main() {
    int green=0,yellow=0,red=0;
    char barchasb[6];
    scanf("%s", barchasb);

    for (int i = 0; i < 5; i++) {
        switch (barchasb[i])
        {
        case 'G':green++; break;
        case 'R':red++; break;
        case 'Y':yellow++; break;

        default:
            break;
        }
    }
    if (red == 3 || red == 2 && yellow == 2 || green == 0)
        printf("nakhor lite");
    else
        printf("rahat baash");

    return 0;
}
