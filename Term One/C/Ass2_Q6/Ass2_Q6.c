/*
 * Ass2_Q6.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int n, count, i = 1;
	long sum = 0;
	while (i) {
		fflush(stdin);
		printf("Enter a positive integer : ");
		scanf("%d", &n);

		for (count = 1; count <= n; count++)
			sum += count;

		fflush(stdin);
		printf("Sum of all Natural numbers up to '%d'  =  %ld \n", n, sum);
		sum = 0;
		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
