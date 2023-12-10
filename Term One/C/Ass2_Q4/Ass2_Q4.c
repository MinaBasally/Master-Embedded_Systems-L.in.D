/*
 * Ass2_Q4.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	double x;
	while (i) {
		fflush(stdin);
		printf("Enter a number : ");
		scanf("%lf", &x);

		if (x > 0) {
			fflush(stdin);
			printf("%.3lf  is positive \n", x);
		} else if (x < 0) {
			fflush(stdin);
			printf("%.3lf  is negative \n", x);
		} else {
			fflush(stdin);
			printf("You entered ZERO \n");
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
