#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

int pickTheBest(char** list, int l, int r) {
	int ans = l, i1, i2, f1, f2;
	bool i1_isLower, i2_isLower, f1_isLower, f2_isLower;



	for (int i = l + 1; i < r + 1; i++) {
		i1 = list[i][0];  i2 = list[i][1];
		f1 = list[ans][0];  f2 = list[ans][1];
		int mp = strlen(list[i]);
		if (i1 > 95) {
			i1_isLower = true;
		}
		else {
			i1_isLower = false;
			i1 += 32;
		}
		//
		if (i2 > 95) {
			i2_isLower = true;
		}
		else {
			i2_isLower = false;
			i2 += 32;
		}
		//
		if (f1 > 95) {
			f1_isLower = true;
		}
		else {
			f1_isLower = false;
			f1 += 32;
		}
		//
		if (f2 > 95) {
			f2_isLower = true;
		}
		else {
			f2_isLower = false;
			f2 += 32;
		}
		//

		if (i1 < f1) {
			ans = i;
			continue;
		}
		else if (i1 == f1) {
			if (i1_isLower == false && f1_isLower == true) {
				ans = i;
				continue;
			}
			else if (i1_isLower == true && f1_isLower == false) {
				continue;
			}
			else {//
				if (i2 < f2) {
					ans = i;
					continue;
				}
				else if (i2 == f2) {
					if (i2_isLower == false && f2_isLower == true) {
						ans = i;
						continue;
					}
					else if (i2_isLower == true && f2_isLower == false) {
						continue;
					}
					else {
						if (strlen(list[i]) > strlen(list[ans]))
							continue;
						else if (strlen(list[i]) < strlen(list[ans])) {
							if(mp<2){
							ans = i;
							continue;
							}
							else {
								continue;
							}
						}
						else {
							continue;
						}
					}
				}
				else {
					continue;
				}
			}//
		}
		else {// il>f1
			continue;
		}

	}
	return ans;

}


int main() {
	char** str;
	char* temp;
	char* temp2;
	char* zero = (char*)malloc(sizeof(char) * 2);
	zero[0] = '0';
	zero[1] = '\0';

	str = (char**)malloc(sizeof(char*) * 1005);
	char* buffer = (char*)malloc(sizeof(char) * 1005);

	int word_count = 0;

	for (int i = 0;; i++) {
		scanf("%s", buffer);
		if (strcmp(zero, buffer) == 0) {
			free(buffer);
			free(zero);
			break;
		}
		else {
			word_count++;
			int len = strlen(buffer);
			str[i] = (char*)malloc(sizeof(char) * (len + 1));
			strcpy(str[i], buffer);
		}
	}








	int left = 0, right = word_count - 1;
	for (int i = 0; i < word_count; i++) {
		int ans = pickTheBest(str, left, right);
		temp = str[ans];
		for (int u = ans; u > left; u--) {
			str[u] = str[u - 1];
		}
		str[left] = temp;
		left++;
	}

	for (int i = 0; i < word_count; i++) {
		printf("%s ", str[i]);
		free(str[i]);
	}



	return 0;
}

