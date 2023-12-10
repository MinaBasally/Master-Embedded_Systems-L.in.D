/*
 * Q10.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "conio.h"

char max_ones(int num);

int main() {
	int num, decimal_num, binary_num = 0, i = 1, remainder;
	printf("Enter an integer : ");
	scanf("%d", &num);
	decimal_num = num;

	while (decimal_num != 0) {
		remainder = decimal_num % 2;
		decimal_num /= 2;
		binary_num += remainder * i;
		i *= 10;
	}

	printf("Max. count of successive ones in %d(%d) is %d", num, binary_num, max_ones(num));
	getch();
	return 0;
}

char max_ones(int num) {
	char count = 0;

	while (num != 0) {
		num = (num & (num << 1));
		count++;
	}

	return count;
}
