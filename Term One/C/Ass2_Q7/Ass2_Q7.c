/*
 * Ass2_Q7.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int n, count, i = 1;
	unsigned long fact = 1;

	while (i) {
		fflush(stdin);
		printf("Enter an integer : ");
		scanf("%d", &n);

		if (n >= 0) {
			for (count = 1; count <= n; count++)
				fact *= count;
			fflush(stdin);
			printf("Factorial (%d!)  =  %lu \n", n, fact);
		} else {
			fflush(stdin);
			printf("Math Error! Factorial of a negative number does not exist \n");
		}

		fact = 1;
		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
