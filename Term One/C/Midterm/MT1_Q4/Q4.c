/*
 * Q4.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

void reverse() {
	char x;
	scanf("%c", &x);

	if (x != '\n') {
		reverse();
		printf("%c", x);
	}

}

int main() {
	printf("Enter any characters to be reversed :\n");
	reverse();
	getch();
	return 0;
}
