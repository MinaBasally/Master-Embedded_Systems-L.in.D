/*
 * Ass2_Q8.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mina
 */

#include "stdio.h"

int main() {
	char o;
	int i = 1;
	float n1, n2;

	while (i) {
		fflush(stdin);
		printf("Enter two numbers : ");
		scanf("%f %f", &n1, &n2);
		fflush(stdin);
		printf("Enter '+' , '-' , '*' or '/' : ");
		scanf("%c", &o);

		switch (o) {
		case '+':
			fflush(stdin);
			printf("%.2f + %.2f = %.4f", n1, n2, n1 + n2);
			break;
		case '-':
			fflush(stdin);
			printf("%.2f - %.2f = %.4f", n1, n2, n1 - n2);
			break;
		case '*':
			fflush(stdin);
			printf("%.2f * %.2f = %.4f", n1, n2, n1 * n2);
			break;
		case '/':
			fflush(stdin);
			printf("%.2f / %.2f = %.4f", n1, n2, n1 / n2);
			break;
		default:
			fflush(stdin);
			printf("Error! Enter one of these operators: + , - , * or /");
			break;
		}

		fflush(stdin);
		printf("\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
