/*
 *  LinkedList_APIs.c
 *
 *  Created on: Jan 11, 2024
 *      Author: Mina
 *
 */

#include "LinkedList_APIs.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}



/*Global Pointer to the first student(the first node in the linked list)*/
struct Sstudent *G_PFirstStudent = NULL;



/*Global Counter*/
static unsigned int G_count = 0;



/*APIs Definitions*/

/*Add students manually*/
void AddStudent() {
	struct Sstudent *PNewStudent = (struct Sstudent*) malloc(
			sizeof(struct Sstudent));
	struct Sstudent *PLastStudent;

	if (!(PNewStudent)) {
	} else {
		/*check if the list is empty*/
		if (!(G_PFirstStudent)) {
			G_PFirstStudent = PNewStudent;
			PNewStudent->PNextStudent = NULL;
		} else {
			PLastStudent = G_PFirstStudent;
			while (PLastStudent->PNextStudent)
				PLastStudent = PLastStudent->PNextStudent;
			PLastStudent->PNextStudent = PNewStudent;
			PNewStudent->PNextStudent = NULL;
		}

		defPRINTF("Enter The Student's Data...\n\n\tStudent ID : ");
		scanf("%u", &(PNewStudent->StudentData.ID));

		defPRINTF("\tStudent Name : ");
		fgets(PNewStudent->StudentData.Name, MaxNameLength, stdin);
		PNewStudent->StudentData.Name[strlen(PNewStudent->StudentData.Name) - 1] =
				'\0';

		defPRINTF("\tStudent Birthdate(day/month/year) : ");
		scanf("%u/%u/%u", &(PNewStudent->StudentData.Birthdate.Day),
				&(PNewStudent->StudentData.Birthdate.Month),
				&(PNewStudent->StudentData.Birthdate.Year));

		defPRINTF("\tStudent Height(cm.) : ");
		scanf("%f", &(PNewStudent->StudentData.Height));

		G_count++;
	}

}



/*Find students by Their IDs and Delete them*/
int DeleteStudent() {
	struct Sstudent *PSelectedStudent;
	struct Sstudent *PPreviousStudent;
	unsigned int SelectedID;

	defPRINTF("\nEnter The ID of the student you want to delete : ");
	scanf("%u", &SelectedID);

	PSelectedStudent = G_PFirstStudent;
	PPreviousStudent = NULL;

	while (G_PFirstStudent) {
		if (PSelectedStudent) {
			if (PSelectedStudent->StudentData.ID == SelectedID) {
				if (PPreviousStudent)
					PPreviousStudent->PNextStudent =
							PSelectedStudent->PNextStudent;
				else
					G_PFirstStudent = PSelectedStudent->PNextStudent;

				free(PSelectedStudent);
				defPRINTF("Deletion...DONE\n\n");
				G_count--;
				return 1;
			} else {
				PPreviousStudent = PSelectedStudent;
				PSelectedStudent = PSelectedStudent->PNextStudent;
			}
		} else {
			defPRINTF("\nThe ID was not found!!!\n\n");
			return 0;
		}

	}

	defPRINTF("The students list is empty!!!\n\n");

	return 0;
}



/*Print All The Data*/
void ShowEntireList() {
	struct Sstudent *PCurrentStudent = G_PFirstStudent;
	unsigned int temp;

	if (G_count) {
		temp = 1;
		defPRINTF("*** Displaying a total of %u student(s)...\n", G_count);
	} else {
		G_PFirstStudent = NULL;
		defPRINTF("The students list is empty!!!\n");
	}

	while (G_PFirstStudent) {
		if (PCurrentStudent) {
			defPRINTF("Student #%u :-\n", temp++);
			defPRINTF("Student ID : %u\n", PCurrentStudent->StudentData.ID);
			defPRINTF("Student Name : %s\n", PCurrentStudent->StudentData.Name);
			defPRINTF("Student Birthdate(day/month/year) : ");
			defPRINTF("%.2u / %.2u / %u\n",
					PCurrentStudent->StudentData.Birthdate.Day,
					PCurrentStudent->StudentData.Birthdate.Month,
					PCurrentStudent->StudentData.Birthdate.Year);
			defPRINTF("Student Height : %.1f cm.\n\n",
					PCurrentStudent->StudentData.Height);
			PCurrentStudent = PCurrentStudent->PNextStudent;
		} else {
			defPRINTF("The End!\n");
			break;
		}
	}

}



/*Delete All The Data*/
void DeleteAll() {
	struct Sstudent *PCurrentStudent = G_PFirstStudent;
	struct Sstudent *PTemp;

	if (!(G_count)) {
		G_PFirstStudent = NULL;
		defPRINTF("The students list is empty!!!\n");
	} else {
		defPRINTF("*** Deleting a total of %u student(s)...\n", G_count);
	}

	while (G_PFirstStudent) {
		if (PCurrentStudent) {
			PTemp = PCurrentStudent;
			PCurrentStudent = PCurrentStudent->PNextStudent;
			free(PTemp);
			G_count--;
		} else {
			G_PFirstStudent = NULL;
			defPRINTF("Deletion...Done!..\nThe students list is empty now!\n");
		}
	}

}



/*Find students by Their List Numbers and Print them*/
void GetNth() {
	struct Sstudent *PCurrentStudent = G_PFirstStudent;
	unsigned int SelectedIndex, CurrentIndex = 0;

	defPRINTF("\nEnter The List Number of the student : ");
	scanf("%u", &SelectedIndex);

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	}

	while (G_PFirstStudent) {
		if (PCurrentStudent) {
			CurrentIndex++;
			if (CurrentIndex == SelectedIndex) {
				defPRINTF("Student at index (%u) :-\n", CurrentIndex);
				defPRINTF("Student ID : %u\n", PCurrentStudent->StudentData.ID);
				defPRINTF("Student Name : %s\n",
						PCurrentStudent->StudentData.Name);
				defPRINTF("Student Birthdate(day/month/year) : ");
				defPRINTF("%.2u / %.2u / %u\n",
						PCurrentStudent->StudentData.Birthdate.Day,
						PCurrentStudent->StudentData.Birthdate.Month,
						PCurrentStudent->StudentData.Birthdate.Year);
				defPRINTF("Student Height : %.1f cm.\n\n",
						PCurrentStudent->StudentData.Height);
				break;
			} else {
				PCurrentStudent = PCurrentStudent->PNextStudent;
			}
		} else {
			defPRINTF("\nDoes Not Exist...Index exceeded the limit!\n\n");
			break;
		}
	}
}



/*Find The Total Number of students using an Iterative Method and Print it*/
void GetLength_iterative() {
	struct Sstudent *PCurrentStudent = G_PFirstStudent;
	unsigned int Count = 0;

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	}

	while (G_PFirstStudent) {
		if (PCurrentStudent) {
			Count++;
			PCurrentStudent = PCurrentStudent->PNextStudent;
		} else {
			defPRINTF("Total number of students = %u\n", Count);
			break;
		}
	}
}



/*Find The Total Number of students using a Recursive Method and Print it*/
unsigned int GetLength_recursive(struct Sstudent *PCurrentStudent) {
	if (PCurrentStudent)
		return 1 + GetLength_recursive(PCurrentStudent->PNextStudent);
	else
		return 0;
}
void PrintLength_recursive() {
	unsigned int L;

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	} else {
		L = GetLength_recursive(G_PFirstStudent);
		defPRINTF("Total number of students = %u\n", L);
	}
}



/*Find students by Their Numbers from The List End and Print them*/
void GetNthFromTheEnd() {
	struct Sstudent *PStudentRef = G_PFirstStudent;
	struct Sstudent *PStudentMain = G_PFirstStudent;
	unsigned int SelectedIndex, i;

	defPRINTF("\nEnter The number of the student from The List End : ");
	scanf("%u", &SelectedIndex);

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	} else {
		for (i = 1; i <= SelectedIndex; i++) {
			PStudentRef = PStudentRef->PNextStudent;
			if (!(PStudentRef) && (i < SelectedIndex)) {
				defPRINTF(
						"\nDoes Not Exist...The Number Is Outside The List Range!\n\n");
				PStudentMain = NULL;
				break;
			}
		}
	}

	while (G_PFirstStudent) {
		if (PStudentMain && PStudentRef) {
			PStudentMain = PStudentMain->PNextStudent;
			PStudentRef = PStudentRef->PNextStudent;
		} else if (PStudentMain) {
			defPRINTF("Student at index (%u) from The End :-\n", SelectedIndex);
			defPRINTF("Student ID : %u\n", PStudentMain->StudentData.ID);
			defPRINTF("Student Name : %s\n", PStudentMain->StudentData.Name);
			defPRINTF("Student Birthdate(day/month/year) : ");
			defPRINTF("%.2u / %.2u / %u\n",
					PStudentMain->StudentData.Birthdate.Day,
					PStudentMain->StudentData.Birthdate.Month,
					PStudentMain->StudentData.Birthdate.Year);
			defPRINTF("Student Height : %.1f cm.\n\n",
					PStudentMain->StudentData.Height);
			break;
		} else {
			break;
		}
	}
}



/*Print The Student in The Middle of the list*/
void GetTheMiddleNode() {
	struct Sstudent *PStudentFast = G_PFirstStudent;
	struct Sstudent *PStudentSlow = G_PFirstStudent;
	unsigned int i, MiddleIndex = 0;

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	}

	while (G_PFirstStudent) {
		MiddleIndex++;
		PStudentFast = PStudentFast->PNextStudent;
		if (!(PStudentFast)) {
			defPRINTF("The Middle student is...\n");
			defPRINTF("List Number : (%u)\n", MiddleIndex);
			defPRINTF("Student ID : %u\n", PStudentSlow->StudentData.ID);
			defPRINTF("Student Name : %s\n", PStudentSlow->StudentData.Name);
			defPRINTF("Student Birthdate(day/month/year) : ");
			defPRINTF("%.2u / %.2u / %u\n",
					PStudentSlow->StudentData.Birthdate.Day,
					PStudentSlow->StudentData.Birthdate.Month,
					PStudentSlow->StudentData.Birthdate.Year);
			defPRINTF("Student Height : %.1f cm.\n\n",
					PStudentSlow->StudentData.Height);
			break;
		} else {
			PStudentFast = PStudentFast->PNextStudent;
			if (!(PStudentFast)) {
				defPRINTF("The Middle students are...\n");
				for (i = 0; i < 2; i++) {
					defPRINTF("List Number : (%u)\n", MiddleIndex++);
					defPRINTF("Student ID : %u\n", PStudentSlow->StudentData.ID);
					defPRINTF("Student Name : %s\n",
							PStudentSlow->StudentData.Name);
					defPRINTF("Student Birthdate(day/month/year) : ");
					defPRINTF("%.2u / %.2u / %u\n",
							PStudentSlow->StudentData.Birthdate.Day,
							PStudentSlow->StudentData.Birthdate.Month,
							PStudentSlow->StudentData.Birthdate.Year);
					defPRINTF("Student Height : %.1f cm.\n\n",
							PStudentSlow->StudentData.Height);
					PStudentSlow = PStudentSlow->PNextStudent;
				}
				break;
			} else {
				PStudentSlow = PStudentSlow->PNextStudent;
			}
		}
	}
}



/*Detect if the list contains any Loops*/
void DetectLoop() {
	struct Sstudent *PStudentSlow = G_PFirstStudent;
	struct Sstudent *PStudentFast = G_PFirstStudent;

	while (PStudentSlow && PStudentFast && PStudentFast->PNextStudent) {
		PStudentFast = PStudentFast->PNextStudent->PNextStudent;
		PStudentSlow = PStudentSlow->PNextStudent;
		if (PStudentSlow == PStudentFast) {
			defPRINTF("Loop is FOUND\n");
			break;
		}
	}

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	} else if (!(G_PFirstStudent->PNextStudent)
			|| (PStudentSlow != PStudentFast)) {
		defPRINTF("No Loops Found\n");
	}
}



/*Reverse The Order of The Linked List*/
void ReverseLinkedList() {
	struct Sstudent *PPrevious = NULL;
	struct Sstudent *PCurrent = G_PFirstStudent;
	struct Sstudent *PNext;

	while (G_PFirstStudent && PCurrent) {
		PNext = PCurrent->PNextStudent;
		PCurrent->PNextStudent = PPrevious;
		PPrevious = PCurrent;
		PCurrent = PNext;
	}

	if (!(G_PFirstStudent)) {
		defPRINTF("The students list is empty!!!\n\n");
	} else {
		G_PFirstStudent = PPrevious;
		defPRINTF("Reversing List...Done\n\n");
	}
}
