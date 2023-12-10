/*
 * Ass4_Q2.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int j, i = 1;
	char s[1000];

	while (i) {
		fflush(stdin);
		printf("Enter a string : ");
		gets(s);

		for (j = 0; s[j] != '\0'; j++);

		fflush(stdin);
		printf("\nLength of string = %d", j);
		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
