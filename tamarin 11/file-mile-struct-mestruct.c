#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)
typedef struct input {
	int id;
	char name[20];
} input ;

int main() {
	int n;
	scanf("%d", &n);
	input temp;
	FILE* binfile = NULL;
	binfile = fopen("data.bin", "rb+");

	


	if (binfile) {
		for (int i = 0; i < n - 1; i++)
			fseek(binfile, sizeof(input), SEEK_CUR);


		if (fgetc(binfile) != EOF) {
			fseek(binfile, -1, SEEK_CUR);


			fread(&temp, sizeof(input), 1, binfile);
			printf("%d:%s\n", temp.id, temp.name);
		}

	fclose(binfile);
	}
	else {
		fprintf(stderr, "file didn't open seccessfully");
		return -1;
	}
	return 0;
}
