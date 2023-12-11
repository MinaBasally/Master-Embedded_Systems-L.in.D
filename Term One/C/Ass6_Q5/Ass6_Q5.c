/*
 * Ass6_Q5.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Mina
 */

#include "stdio.h"
#define Pi 3.14159265359
#define area(r) (Pi*r*r)

int main() {
	int i = 1;
	double r;

	while (i) {
		fflush(stdin);
		printf("****Area of a CIRCLE****");
		fflush(stdin);
		printf("\n\nEnter the Radius : ");
		scanf("%lf", &r);
		fflush(stdin);
		printf("\nArea = %.3lf", area(r));
		fflush(stdin);
		printf("\n\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
