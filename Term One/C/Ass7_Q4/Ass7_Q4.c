/*
 * Ass7_Q4.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Mina
 */

#include "stdio.h"
#define max_length 30

int main() {
	int i = 1, j, n, arr[max_length], *ptr = arr;

	while (i) {
		fflush(stdin);
		printf("\nEnter the number of elements of the array(max. 30) : ");
		scanf("%d", &n);

		for (j = 0; j < n; j++) {
			fflush(stdin);
			printf("\nEnter element #%d : ", j + 1);
			scanf("%d", &arr[j]);
		}

		fflush(stdin);
		printf("\n\nYour array in a reversed order...");

		for (j = n - 1; j >= 0; j--) {
			fflush(stdin);
			printf("\n\nElement #%d : %d", j + 1, *(ptr + j));
		}

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
