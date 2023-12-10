/*
 * Ass2_Q1.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	long x;
	while (i) {
		fflush(stdin);
		printf("Enter an integer : ");
		scanf("%ld", &x);

		if (x % 2 == 0) {
			fflush(stdin);
			printf("%ld is even \n", x);
		} else {
			fflush(stdin);
			printf("%ld is odd \n", x);
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
