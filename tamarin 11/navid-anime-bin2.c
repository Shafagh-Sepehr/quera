#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#pragma warning(disable:4996)


char uppercase(char c) {
    if (c > 96 && c <= 122)
        c -= 32;
    return c;
}
char lowecase(char c) {
    if (c <= 90 && c >= 65)
        c += 32;
    return c;
}

void change_name(char esm[1000]) {
    
    esm[0] = uppercase(esm[0]);
    int len = strlen(esm);
   

    for (int k = 1; esm[k] != '\0'; k++) {
        if (esm[k] == ' ') {
            esm[k + 1] = uppercase(esm[k + 1]);
            k++;
        }
        else
            esm[k] = lowecase(esm[k]);

    }
    return ;
}
void make_address(char* esm,char* address, char *fstr) {
    strcpy(fstr, address);
    char temp[3] = "/\0";
    strcat(fstr,temp);
    strcat(fstr, esm);
}

int main() {
    char address[100];
    scanf("%s", address);
    //printf("%s", address);

    
    
    DIR* dir = NULL;
    dir = opendir(address);
    if (!dir) {
        fprintf(stderr, "address opening failed");
        return -1;
    }

    int ctr = 0;
    for (struct dirent* dir_temp; (dir_temp = readdir(dir)) != NULL;ctr++) {
        if (ctr > 1) {
            char old[1000], new[1000], esm[1000];

            sprintf(esm, "%s", dir_temp->d_name);

            make_address(esm, address, old);

            change_name(esm);

            make_address(esm, address, new);
            rename(old, new);
        }

       
    } 
    closedir(dir);

    return 0;
}
