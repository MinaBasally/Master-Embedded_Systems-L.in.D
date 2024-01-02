/*
 * Ass7_Q1.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1, m, *ab;

	while (i) {
		m = 29;
		fflush(stdin);
		printf(">>> {m = %d}", m);
		fflush(stdin);
		printf("\n\nThe memory address of 'm' : %p", &m);
		fflush(stdin);
		printf("\n\nThe value of 'm' : %d", m);

		ab = &m;
		fflush(stdin);
		printf("\n\n\n>>> {ab = &m}");
		fflush(stdin);
		printf("\n\nThe memory address that pointer 'ab' is pointing to : %p", ab);
		fflush(stdin);
		printf("\n\nThe content of pointer 'ab' : %d", *ab);

		m = 34;
		fflush(stdin);
		printf("\n\n\n>>> {m = %d}", m);
		fflush(stdin);
		printf("\n\nThe memory address that pointer 'ab' is pointing to : %p", ab);
		fflush(stdin);
		printf("\n\nThe content of pointer 'ab' : %d", *ab);

		*ab = 7;
		fflush(stdin);
		printf("\n\n\n>>> {*ab = %d}", m);
		fflush(stdin);
		printf("\n\nThe memory address of 'm' : %p", &m);
		fflush(stdin);
		printf("\n\nThe value of 'm' : %d", m);

		fflush(stdin);
		printf("\n\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
