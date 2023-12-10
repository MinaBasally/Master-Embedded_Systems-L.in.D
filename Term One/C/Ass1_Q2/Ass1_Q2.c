/*
 * Ass1_Q2.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	int x;
	while (i) {
		fflush(stdin);
		printf("Enter an integer : ");
		scanf("%d", &x);
		fflush(stdin);
		printf("You entered : %d \n", x);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n");
	}
	return 0;
}
