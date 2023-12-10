/*
 * Q2.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

double squareRoot(int num) {
	double x = num;
	double y = 1;
	double epsilon = 0.0000001;

	while (x - y > epsilon) {
		x = (x + y) / 2;
		y = num / x;
	}

	return x;
}

int main() {
	int num;
	printf("Enter a positive integer : ");
	scanf("%d", &num);
	double result = squareRoot(num);
	printf("Square Root of (%d) = %.3lf\n", num, result);
	getch();
	return 0;
}
