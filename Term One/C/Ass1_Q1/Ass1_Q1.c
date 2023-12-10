/*
 * Ass1_Q1.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int i = 1;
	char sentence[200];
	while (i) {
		fflush(stdin);
		printf("Enter a sentence : ");
		gets(sentence);
		fflush(stdin);
		printf("You entered this sentence : %s \n", sentence);
		fflush(stdin);
		printf("again = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n");
	}
	return 0;
}
