/*
 * Ass5_Q4.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "Math.h"

long double power(double b, double p);

int main() {
	int i = 1;
	double b, p, g;

	while (i) {
		fflush(stdin);
		printf("Enter a number(the base) : ");
		scanf("%lf", &b);
		fflush(stdin);
		printf("\nEnter a non-negative integer(the power) : ");
		scanf("%lf", &p);

		while (p < 0 || (modf(p, &g) != 0)) {
			fflush(stdin);
			printf("\nError! Please, enter a non-negative integer : ");
			scanf("%lf", &p);
		}

		fflush(stdin);
		printf("\n(%.2lf)^%.0lf = %.3Lf", b, p, power(b, p));
		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}

long double power(double b, double p) {

	if (p != 0)
		return (b * power(b, p - 1));

	return 1;
}
