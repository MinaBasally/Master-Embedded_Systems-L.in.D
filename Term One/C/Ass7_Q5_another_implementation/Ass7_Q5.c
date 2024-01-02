/*
 * Ass7_Q5.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "string.h"
#define max_length 100
#define max_entries 3

typedef struct Semployee {
	char name[max_length];
	unsigned int ID;
} employee;

int main() {
	int i = 1, k;

	static employee emp_1 = { "John", 1001 };
	static employee emp_2 = { "Alex", 1002 };
	static employee emp_3 = { "Taylor", 1003 };

	employee (*arr[max_entries]) = { &emp_1, &emp_2, &emp_3 };
	employee (*(*ptr)[max_entries]) = &arr;

	while (i) {
		fflush(stdin);
		printf("\n\n****Displaying the employees'database****");

		for (k = 0; k < max_entries; k++) {
			fflush(stdin);
			printf("\n\nEmployee #%d", k + 1);
			fflush(stdin);
			printf("\nName : %s", (char*) (*(*ptr + k))->name);
			fflush(stdin);
			printf("\nID : %u", (unsigned int*) ((*(*ptr + k))->ID));
		}

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
