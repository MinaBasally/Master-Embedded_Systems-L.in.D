/*
 * Ass1_Q4.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	float x, y;
	double product;
	while (i) {
		fflush(stdin);
		printf("Enter two numbers : ");
		scanf("%f %f", &x, &y);
		product = x * y;
		fflush(stdin);
		printf("Product : %lf \n", product);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n");
	}
	return 0;
}
