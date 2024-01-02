/*
 * Ass7_Q5.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "string.h"
#define max_length 50
#define max_entries 100

typedef struct Semployee {
	char name[max_length];
	unsigned int ID;
} employee;

int main() {
	int i = 1, j, k, q;

	employee (*arr[max_entries]);
	employee (*(*ptr)[max_entries]) = &arr;

	while (i) {
		fflush(stdin);
		printf("****Create a database for the employees****");

		for (j = 0; j < max_entries; j++) {
			fflush(stdin);
			printf("\n\nEmployee #%d\nEnter the employee's name = ", j + 1);
			fgets((*(*ptr + j))->name, max_length, stdin);
			(*(*ptr + j))->name[strlen((*(*ptr + j))->name) - 1] = '\0';
			fflush(stdin);
			printf("Enter the employee's ID : ");
			scanf("%u", (unsigned int*) (&((*(*ptr + j))->ID)));
			fflush(stdin);
			printf("\nEnter another employee? Yes = 1...No = 0 : ");
			scanf("%d", &q);
			if (q == 0)
				break;
		}

		fflush(stdin);
		printf("\n\n****Displaying the employees'database****");

		for (k = 0; k <= j; k++) {
			fflush(stdin);
			printf("\n\nEmployee #%d", k + 1);
			fflush(stdin);
			printf("\nName : %s", (*(*ptr + k))->name);
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
