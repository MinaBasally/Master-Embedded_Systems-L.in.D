/*
 * Ass1_Q6.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	float x, y, temp;
	while (i) {
		fflush(stdin);
		printf("Enter the value of x : ");
		scanf("%f", &x);
		fflush(stdin);
		printf("Enter the value of y : ");
		scanf("%f", &y);
		temp = x;
		x = y;
		y = temp;
		fflush(stdin);
		printf("\nAfter swapping, x = %f \n", x);
		fflush(stdin);
		printf("After swapping, y = %f \n\n", y);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
