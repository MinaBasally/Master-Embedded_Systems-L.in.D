/*
 * Ass1_Q5.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	char c;
	while (i) {
		fflush(stdin);
		printf("Enter a character : ");
		scanf("%c", &c);
		fflush(stdin);
		printf("The ASCII code of character  '%c'  is : %d \n", c ,c);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n");
	}
	return 0;
}
