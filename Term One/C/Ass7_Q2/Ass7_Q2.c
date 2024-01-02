/*
 * Ass7_Q2.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1, j;
	char alphabet[26], *ptr;

	while (i) {
		ptr = alphabet;

		for (j = 0; j < 26; j++) {
			*(ptr++) = 'A' + j;
		}

		ptr = alphabet;
		fflush(stdin);
		printf("\nThe English Alphabet is :\n\n");

		for (j = 0; j < 26; j++) {
			fflush(stdin);
			printf("%c    ", *(ptr++));
		}

		fflush(stdin);
		printf("\n\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
