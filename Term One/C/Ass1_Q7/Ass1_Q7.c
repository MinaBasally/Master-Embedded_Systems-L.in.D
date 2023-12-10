/*
 * Ass1_Q7.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	double x, y;
	while (i) {
		fflush(stdin);
		printf("Enter the value of x : ");
		scanf("%lf", &x);
		fflush(stdin);
		printf("Enter the value of y : ");
		scanf("%lf", &y);
		x = x + y;
		y = x - y;
		x = x - y;
		fflush(stdin);
		printf("\nAfter swapping, x = %.5lf \n", x);
		fflush(stdin);
		printf("After swapping, y = %.5lf \n\n", y);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
