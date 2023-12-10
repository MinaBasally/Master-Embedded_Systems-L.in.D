/*
 * Ass1_Q3.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	int x, y;
	long sum;
	while (i) {
		fflush(stdin);
		printf("Enter two integers : ");
		scanf("%d %d", &x, &y);
		sum = x + y;
		fflush(stdin);
		printf("Sum : %d \n", sum);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n");
	}
	return 0;
}
