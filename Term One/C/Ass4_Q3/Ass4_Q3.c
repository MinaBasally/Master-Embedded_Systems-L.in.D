/*
 * Ass4_Q3.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	int j, k, l, i = 1;
	char s[1000], temp;

	while (i) {
		fflush(stdin);
		printf("Enter a string..... : ");
		gets(s);

		for (l = 0; s[l] != '\0'; l++);

		for (j = 0, k = l - 1; j < k; j++, k--) {
			temp = s[j];
			s[j] = s[k];
			s[k] = temp;
		}

		fflush(stdin);
		printf("\nThe reversed string : %s", s);
		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
