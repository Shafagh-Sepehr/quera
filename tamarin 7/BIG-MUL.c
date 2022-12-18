#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define cSIZE 120
#pragma warning(disable:4996)



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



void mul(char* a, char* b) {

  char* tempstr ;
  char* tempstrtemp = (char*)calloc(cSIZE, sizeof(char));
  char* cp ;
  
  tempstrtemp[0] = '0';
  tempstrtemp[0] = '\0';
  int len1, len2, temp, cIndex = cSIZE - 2, ctr0 = 0;
  short strg=0;
  
  len1 = strlen(a);
  len2 = strlen(b);
  if (len2 > len1) {
    mul(b, a);
    return;
  }
  
  
  for (int n = len2 - 1; n >= 0; n--,ctr0++) {//b[n]
    
    cIndex = cSIZE - 2;
    cp = (char*)calloc(cSIZE, sizeof(char));
    tempstr = (char*)calloc(cSIZE+1, sizeof(char));
    if(ctr0)strcpy(cp, tempstrtemp);


    for (int m = len1 - 1; m >= 0; m--) {//a[m]
      temp = (b[n] - '0') * (a[m] - '0');

      if (strg) { temp += strg; strg = 0; }

      if (temp > 9) {
        tempstr[cIndex] = temp % 10 + '0';
        cIndex--;
        strg = temp / 10;
      }
      else {
        tempstr[cIndex] = temp +'0';
        cIndex--;
      }

    }
    if (strg) { tempstr[cIndex] = strg+'0'; strg = 0; cIndex--;}
    while (tempstr[0] == NULL) {
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
  printf("%s",tempstrtemp);
  
  
  return;
}

int main() {
  //char firstnum[80], secondnum[80],c[90];
  char* firstnum = (char*)malloc(sizeof(char) * 80);
  char* secondnum = (char*)malloc(sizeof(char) * 80);
  

  scanf("%s\n%s", firstnum, secondnum);


  mul(firstnum, secondnum);
  


  return 0;
}
