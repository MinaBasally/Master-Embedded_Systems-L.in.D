/*
 * Ass5_Q2.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Mina
 */

#include "stdio.h"

unsigned long fact(int x);

int main() {
	int n, i = 1;

	while (i) {
		fflush(stdin);
		printf("Enter an integer : ");
		scanf("%d", &n);

		if (n >= 0) {
			fflush(stdin);
			printf("\nFactorial (%d!) = %lu\n", n, fact(n));
		} else {
			fflush(stdin);
			printf("\nMath Error! Factorial of a negative number does not exist.\n");
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}

unsigned long fact(int x) {

	if (x != 0)
		return (x * fact(x - 1));

	return 1;
}
