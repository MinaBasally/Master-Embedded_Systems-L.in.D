/*
 * Q3.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

int c = 0;

int check_prime(int n) {
	int j, flag = 0;

	for (j = 2; j <= n / 2; j++)
		if (n % j == 0) {
			flag = 1;
			return flag;
		}

	c++; return flag;
}

int main() {
	int n1, n2, flag, j;

	fflush(stdin);
	printf("Enter two integer values to find the prime numbers which are included in this interval : ");
	scanf("%d %d", &n1, &n2);

	for (j = n1 + 1; j < n2; j++) {
		flag = check_prime(j);
		if (flag == 0) {
			if (c == 1)
				printf("\nThe *prime number(s)* between '%d' & '%d' is(are) : ", n1, n2);
			printf("%d  ", j);
		}
		if (j == (n2 - 1)) {
			fflush(stdin); printf(" [*%d* prime number(s)]", c);
		}
	}

	if (c == 0) {
		fflush(stdin); printf("\nThere are no *prime numbers* between '%d' & '%d'.", n1, n2);
	}

	getch(); return 0;
}
