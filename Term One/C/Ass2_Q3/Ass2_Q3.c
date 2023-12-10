/*
 * Ass2_Q3.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	double x, y, z;
	while (i) {
		fflush(stdin);
		printf("Enter three different numbers : ");
		scanf("%lf %lf %lf", &x, &y, &z);

		if (x > y) {
			if (x > z) {
				fflush(stdin);
				printf("The LARGEST number is  %.4lf \n", x);
			} else {
				fflush(stdin);
				printf("The LARGEST number is  %.4lf \n", z);
			}
		} else if (y > z) {
			fflush(stdin);
			printf("The LARGEST number is  %.4lf \n", y);
		} else {
			fflush(stdin);
			printf("The LARGEST number is  %.4lf \n", z);
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}
	return 0;
}
