/*
 * Ass4_Q1.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int j, count, i = 1;
	char c, s[1000];

	while (i) {
		fflush(stdin);
		printf("Enter a string : ");
		gets(s);

		fflush(stdin);
		printf("\nEnter a character to find its frequency : ");
		scanf("%c", &c);
		count = 0;

		for (j = 0; s[j] != '\0'; j++)
			if (s[j] == c)
				count++;

		if (count == 0) {
			fflush(stdin);
			printf("\nCharacter '%c' was *Not found*", c);
		} else {
			fflush(stdin);
			printf("\nThe frequency of character '%c' = %d", c, count);
		}

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
