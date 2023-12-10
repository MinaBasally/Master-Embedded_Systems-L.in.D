/*
 * Q1.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

unsigned short myfun(unsigned short num) {
	static unsigned short new_num = 0;
	int rem;

	if (num != 0) {
		rem = num % 10;
		new_num += rem;
		;
		myfun(num / 10);
	} else
		return 0;

	return new_num;
}

int main() {
	unsigned short num = 123;
	printf("%hu", myfun(num));
	getch();
	return 0;
}
