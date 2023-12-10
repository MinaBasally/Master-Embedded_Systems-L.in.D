/*
 * Ass2_Q2.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	char c;
	while (i) {
		fflush(stdin);
		printf("Enter an English letter(a,b,c,d,e,...) : ");
		scanf("%c", &c);

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A'
				|| c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			fflush(stdin);
			printf("'%c' is a vowel \n", c);
		} else {
			fflush(stdin);
			printf("'%c' is a consonant \n", c);
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
