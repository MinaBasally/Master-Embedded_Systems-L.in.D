/*
 * Ass3_Q1.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int m, n, i = 1;
	float a[2][2], b[2][2], c[2][2];

	while (i) {
		fflush(stdin);
		printf("Enter the elements of the 1st matrix :\n");
		for (m = 0; m < 2; m++)
			for (n = 0; n < 2; n++) {
				fflush(stdin);
				printf("Enter element a(%d,%d) : ", m + 1, n + 1);
				scanf("%f", &a[m][n]);
			}

		fflush(stdin);
		printf("\nEnter the elements of the 2nd matrix :\n");
		for (m = 0; m < 2; m++)
			for (n = 0; n < 2; n++) {
				fflush(stdin);
				printf("Enter element b(%d,%d) : ", m + 1, n + 1);
				scanf("%f", &b[m][n]);
			}

		fflush(stdin);
		printf("\nSum of the two matrices =\n");
		for (m = 0; m < 2; m++)
			for (n = 0; n < 2; n++) {
				c[m][n] = a[m][n] + b[m][n];
				fflush(stdin);
				printf("%.2f\t", c[m][n]);
				fflush(stdin);
				if (n == 1)
					printf("\n");
			}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
