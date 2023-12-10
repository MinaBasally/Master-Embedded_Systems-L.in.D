/*
 * Q11.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "string.h"

int main() {
    int a = 5, b = 10, c;
    int *p = &a, *q = &b;
    c = p - q;
    printf("%d", c);
	return 0;
}
