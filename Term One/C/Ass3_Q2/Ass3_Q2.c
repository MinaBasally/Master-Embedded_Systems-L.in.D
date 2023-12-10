/*
 * Ass3_Q2.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int n, j, i = 1;
	float a[100], avg, sum = 0.0;

	while (i) {
		fflush(stdin);
		printf("Enter the number of elements(Max. = 100 elements) : ");
		scanf("%d", &n);

		while (n > 100 || n <= 0) {
			fflush(stdin);
			printf(
					"Error! The number you entered is out of range...\nEnter a number in the range of (1 to 100) : ");
			scanf("%d", &n);
		}

		fflush(stdin);
		printf("\n");

		for (j = 0; j < n; j++) {
			fflush(stdin);
			printf("Enter element #%d : ", j + 1);
			scanf("%f", &a[j]);
			sum += a[j];
		}

		avg = sum / n;
		fflush(stdin);
		printf("\nThe Average =  %.3f", avg);

		sum = 0.0;
		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
