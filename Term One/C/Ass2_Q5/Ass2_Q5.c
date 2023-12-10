/*
 * Ass2_Q5.c
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
		printf("Enter a character : ");
		scanf("%c", &c);

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			fflush(stdin);
			printf("'%c' Belongs to the English alphabet \n", c);
		} else {
			fflush(stdin);
			printf("'%c' Does not belong to the English alphabet \n", c);
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
