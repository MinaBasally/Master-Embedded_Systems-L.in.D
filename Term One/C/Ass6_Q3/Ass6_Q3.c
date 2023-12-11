/*
 * Ass6_Q3.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Mina
 */

#include "stdio.h"
#define max_entries 20

typedef struct Scomplex {
	float real;
	float imag;
} complex;

complex sum(complex cx[], int j);

int main() {
	int i = 1, j, q;
	complex cx[max_entries], temp;

	while (i) {
		fflush(stdin);
		printf("****Enter any COMPLEX Numbers[(x)+(y)i] to find their sum****");

		for (j = 0; j < max_entries; j++) {
			fflush(stdin);
			printf("\n\nEnter Complex Number #%d...\nReal = ", j + 1);
			scanf("%f", &cx[j].real);
			fflush(stdin);
			printf("Imaginary = ");
			scanf("%f", &cx[j].imag);
			fflush(stdin);
			printf("\nEnter another Complex Number? Yes = 1...No = 0 : ");
			scanf("%d", &q);
			if (q == 0)
				break;
		}

		temp = sum(cx, j);
		fflush(stdin);
		printf("\nSum = (%.2f) + (%.2f)i", temp.real, temp.imag);
		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}

complex sum(complex cx[], int j) {
	int k;
	complex temp = { 0, 0 };

	for (k = 0; k <= j; k++) {
		temp.real = temp.real + cx[k].real;
		temp.imag = temp.imag + cx[k].imag;
	}

	return temp;
}
