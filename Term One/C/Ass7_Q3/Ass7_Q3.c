/*
 * Ass7_Q3.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "string.h"
#define max_length 133

int main() {
	int i = 1, j;
	char string[max_length], *ptr;

	while (i) {
		ptr = string;

		fflush(stdin);
		printf("\nEnter a string : ");
		fgets(string, max_length, stdin);
		fflush(stdin);
		printf("\nThe reverse of the string is : ");

		for (j = strlen(string) - 2; j >= 0; j--) {
			fflush(stdin);
			printf("%c", *(ptr + j));
		}

		fflush(stdin);
		printf("\n\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
