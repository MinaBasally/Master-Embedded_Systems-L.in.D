/*
 * Q6.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

int unique_num(int a[], int size) {
	int res = 0, i;

	for (i = 0; i < size; i++)
		res ^= a[i];

	return res;
}

int main() {
	int a[] = {4, 7, 4, 2, 5, 5, 3, 2, 7, 3, 10}, i;
	int size = sizeof(a) / sizeof(a[0]);

	for (i = 0; i < size; i++)
		printf("%d   ", a[i]);

	printf("\nThe unique number in the array is: %d", unique_num(a, size));
	getch();
	return 0;
}
