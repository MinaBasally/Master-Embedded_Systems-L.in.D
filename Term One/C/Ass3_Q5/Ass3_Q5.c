/*
 * Ass3_Q5.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int n, ele, a[50], j, i = 1;

	while (i) {
		fflush(stdin);
		printf("Enter the number of array elements(Max. = 50 elements) : ");
		scanf("%d", &n);

		while (n > 50 || n <= 0) {
			fflush(stdin);
			printf("Error! The number you entered is out of range...\nEnter a number in the range of (1 to 50) : ");
			scanf("%d", &n);
		}

		for (j = 0; j < n; j++) {
			fflush(stdin);
			printf("Enter element #%d : ", j + 1);
			scanf("%d", &a[j]);
		}

		fflush(stdin);
		printf("\n");

		for (j = 0; j < n; j++) {
			fflush(stdin);
			printf("%d  ", a[j]);
		}

		fflush(stdin);
		printf("\n\nEnter the integer to be searched for : ");
		scanf("%d", &ele);
		j = 0;

		while (j < n && a[j] != ele)
			j++;

		if (j == n) {
			fflush(stdin);
			printf("\n'Not found'");
		} else {
			fflush(stdin);
			printf("\nThe integer '%d' was found at location #%d", ele, j + 1);
		}

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
