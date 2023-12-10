/*
 * Q9.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"
#include "string.h"

void reverse_string(char *str, int size);

int main() {
	char str[100];
	puts("Enter a string :");
	fgets(str, 99, stdin);
	printf("\n");
	reverse_string(str, strlen(str));
	getch();
	return 0;
}

void reverse_string(char *str, int size) {
	int i, j, k = 0;
	char ch[100];

	for (i = size - 2; i >= 0; i--) {
		if (str[i] == ' ') {
			for (j = k - 1; j >= 0; j--) {
				printf("%c", ch[j]);
			}
			printf(" ");
			k = 0;
		} else {
			ch[k] = str[i];
			k++;
		}
	}

	if (k != 0) {
		for (j = k - 1; j >= 0; j--) {
			printf("%c", ch[j]);
		}
	}
}
