/*
 * Ass3_Q3.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int r, c, m, n, i = 1;
	float a[15][15], trans[15][15];

	while (i) {
		fflush(stdin);
		printf("Enter the number of rows and columns respectively(Max. # of rows = 15, Max. # of columns = 15) : ");
		scanf("%d %d", &r, &c);
		fflush(stdin);
		printf("\nEnter the elements of the matrix :\n");

		for (m = 0; m < r; m++)
			for (n = 0; n < c; n++) {
				fflush(stdin);
				printf("Enter element a(%d,%d) : ", m + 1, n + 1);
				scanf("%f", &a[m][n]);
			}

		fflush(stdin);
		printf("\nThe entered matrix =\n");

		for (m = 0; m < r; m++)
			for (n = 0; n < c; n++) {
				fflush(stdin);
				printf("%.2f\t", a[m][n]);
				fflush(stdin);
				if (n == c - 1)
					printf("\n\n");
			}

		fflush(stdin);
		printf("The Transpose =\n");

		for (m = 0; m < c; m++)
			for (n = 0; n < r; n++) {
				trans[m][n] = a[n][m];
				fflush(stdin);
				printf("%.2f\t", trans[m][n]);
				fflush(stdin);
				if (n == r - 1)
					printf("\n\n");
			}

		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
