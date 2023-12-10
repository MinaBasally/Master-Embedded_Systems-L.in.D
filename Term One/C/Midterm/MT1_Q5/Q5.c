/*
 * Q5.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

unsigned char count_ones(int num) {
	unsigned char count=0;
	unsigned char i=0;

	for(i=0; i<32; i++)
	if(num & (1<<i))
	count++;

	return count;
}

int main() {
	int num;
	printf("Enter a positive integer: ");
	scanf("%d", &num);
	printf("Count of ones in '%d' is...%hhu", num, count_ones(num));
	getch();
	return 0;
}
