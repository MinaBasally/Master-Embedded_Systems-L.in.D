/*
 * Q7.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

int sum_int(unsigned int n);

int main() {
	int n = 100;
	int S = sum_int(n);
	printf("Sum of integers from 1 to %d = %d", n, S);
	getch();
	return 0;
}

int sum_int(unsigned int n) {
	static int sum = 0;

	if (n > 0) {
		sum_int(n - 1);
		sum = sum + n;
	}

	return sum;
}
