/*
 * Ass3_Q4.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int n, ele, loc, a[50], j, i = 1;

	while (i) {
		fflush(stdin);
		printf("Enter the number of array elements(Max. = 50 elements) : ");
		scanf("%d", &n);

		while (n > 50 || n <= 0) {
			fflush(stdin);
			printf("Error! The number you entered is out of range...\nEnter a number in the range of (1 to 50) : ");
			scanf("%d", &n);
		}

		fflush(stdin);
		printf("\n");

		for (j = 0; j < n; j++) {
			a[j] = j + 1;
			fflush(stdin);
			printf("%d  ", a[j]);
		}

		fflush(stdin);
		printf("\n\nEnter the element to be inserted : ");
		scanf("%d", &ele);
		fflush(stdin);
		printf("\nEnter the location : ");
		scanf("%d", &loc);

		for (j = n - 1; j >= loc - 1; j--)
			a[j + 1] = a[j];

		a[loc - 1] = ele;

		for (j = 0; j <= n; j++) {
			fflush(stdin);
			printf("%d  ", a[j]);
		}

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
