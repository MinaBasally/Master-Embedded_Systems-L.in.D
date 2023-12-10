/*
 * Q8.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

void reverse_array(int *a, int size);

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, size, i;
	size = sizeof(a) / sizeof(a[0]);

	for (i = 0; i < size; i++)
		printf("%d  ", a[i]);

	reverse_array(a, size);
	printf("\n");

	for (i = 0; i < size; i++)
		printf("%d  ", a[i]);

	getch();
	return 0;
}

void reverse_array(int *a, int size) {
	int temp, j, k;

	for (j = 0, k = size - 1; j < k; j++, k--) {
		temp = a[j];
		a[j] = a[k];
		a[k] = temp;
	}

}
