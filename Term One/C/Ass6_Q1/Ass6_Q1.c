/*
 * Ass6_Q1.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Mina
 */

#include "stdio.h"
#include "string.h"
#define max_length 100
#define max_entries 1000

int main() {
	int i = 1, j, q, k;
	struct Sstudent {
		char name[max_length];
		int roll;
		float mark;
	} students[max_entries];

	while (i) {
		fflush(stdin);
		printf("****Create a students'database****");

		for (j = 0; j < max_entries; j++) {
			fflush(stdin);
			printf("\n\nEnter the student's name : ");
			fgets(students[j].name, max_length, stdin);
			students[j].name[strlen(students[j].name) - 1] = '\0';
			fflush(stdin);
			printf("Enter the student's roll number : ");
			scanf("%d", &students[j].roll);
			fflush(stdin);
			printf("Enter the student's mark : ");
			scanf("%f", &students[j].mark);
			fflush(stdin);
			printf("\nEnter another student? Yes = 1...No = 0 : ");
			scanf("%d", &q);
			if (q == 0)
				break;
		}

		fflush(stdin);
		printf("\n\n****Displaying the students'database****");

		for (k = 0; k <= j; k++) {
			fflush(stdin);
			printf("\n\nStudent #%d", k + 1);
			fflush(stdin);
			printf("\nName : %s", students[k].name);
			fflush(stdin);
			printf("\nRoll number : %d", students[k].roll);
			fflush(stdin);
			printf("\nMark : %.2f", students[k].mark);
		}

		fflush(stdin);
		printf("\n\nagain = 1...exit = 0 : ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\n\n");
	}

	return 0;
}
