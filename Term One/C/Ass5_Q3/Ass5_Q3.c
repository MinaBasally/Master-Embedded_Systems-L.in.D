/*
 * Ass5_Q3.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Mina
 */

#include "stdio.h"

void reverse();

int main() {
	int i = 1;

	while (i) {
		fflush(stdin);
		printf("Enter a sentence to be reversed :\n\n");

		reverse();

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}

void reverse() {
	char c;
	scanf("%c", &c);

	if (c != '\n')
		reverse();

	fflush(stdin);
	printf("%c", c);
}
