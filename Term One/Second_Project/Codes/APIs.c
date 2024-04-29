/*
 *  APIs.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Mina
 *
 */

#include "APIs.h"
#include "FIFO.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}



/*Global Counter*/
static unsigned int G_count = 0;



/*APIs Definitions*/
void getFName(data_type *CS) {
	defPRINTF("\tStudent First Name : ");
	fgets(CS->FName, MaxNameLength, stdin);
	CS->FName[strlen(CS->FName) - 1] = '\0';
	defPRINTF("\n");
}

void getLName(data_type *CS) {
	defPRINTF("\tStudent Last Name : ");
	fgets(CS->LName, MaxNameLength, stdin);
	CS->LName[strlen(CS->LName) - 1] = '\0';
	defPRINTF("\n");
}

void getGPA(data_type *CS) {
	defPRINTF("\tStudent GPA : ");
	scanf("%f", &(CS->GPA));
	defPRINTF("\n");
}

void getRN(unsigned int *temp) {
	defPRINTF("\tStudent Roll Number : ");
	scanf("%u", temp);
	defPRINTF("\n");
}

void getCid(data_type *CS, unsigned int j) {
	defPRINTF("\tCourse %u ID : ", j + 1);
	scanf("%u", &(CS->CourseID[j]));
	defPRINTF("\n");
}

void updFName(data_type *CS) {
	defPRINTF("\tNew First Name : ");
	fgets(CS->FName, MaxNameLength, stdin);
	CS->FName[strlen(CS->FName) - 1] = '\0';
	defPRINTF("[INFO!]...First Name Updated Successfully!\n\n");
	defPRINTF("\n");
}

void updLName(data_type *CS) {
	defPRINTF("\tNew Last Name : ");
	fgets(CS->LName, MaxNameLength, stdin);
	CS->LName[strlen(CS->LName) - 1] = '\0';
	defPRINTF("[INFO!]...Last Name Updated Successfully!\n\n");
}

void updGPA(data_type *CS) {
	defPRINTF("\tNew GPA : ");
	scanf("%f", &(CS->GPA));
	defPRINTF("[INFO!]...GPA Updated Successfully!\n\n");
}

void updRN(unsigned int *temp) {
	defPRINTF("\tNew Roll Number : ");
	scanf("%u", temp);
}

void updCid(data_type *CS, unsigned int j) {
	defPRINTF("\tCourse %u ID : ", j + 1);
	scanf("%u", &(CS->CourseID[j]));
	defPRINTF("\n");
}



/*Add students from A Text File*/
void add_student_from_file() {
	unsigned int i;
	data_type NewStudent;
	FIFO_Buff_Status STATUS;

	FILE *fptr;
	fptr = fopen("data.txt", "r");

	if (fptr == NULL) {
		defPRINTF("[Error!]...File Not Found!\n");
	} else {
		/* Read data from file using fscanf()*/
		while (fscanf(fptr, "%u %s %s %f %u %u %u %u %u %u %u",
				&NewStudent.RollNum, NewStudent.FName, NewStudent.LName,
				&NewStudent.GPA, &NewStudent.CourseID[0],
				&NewStudent.CourseID[1], &NewStudent.CourseID[2],
				&NewStudent.CourseID[3], &NewStudent.CourseID[4],
				&NewStudent.CourseID[5], &NewStudent.CourseID[6])) {

			for (i = 0; i < FIFO_Buff_Students.length; i++) {
				if (Students[i].RollNum == NewStudent.RollNum) {
					defPRINTF("Roll number(%u) is already used!\n",
							NewStudent.RollNum);
					defPRINTF("[ERROR!]...Student Addition...FAILED!\n");
					break;
				}
			}

			if (i == FIFO_Buff_Students.length) {
				STATUS = FIFO_Buff_push(&FIFO_Buff_Students, &NewStudent);
				if (STATUS == FIFO_Buff_No_Error) {
					G_count++;
				} else {
					break;
				}
			}
		}

		fclose(fptr);
	}
}



/*Add students manually*/
void add_student_manually() {
	unsigned int temp, i, j, a;
	data_type NewStudent;
	FIFO_Buff_Status STATUS;

	if (FIFO_Buff_Students.count == FIFO_Buff_Students.length) {
		defPRINTF("Max number of entries(%u) reached!\n\n",
				FIFO_Buff_Students.length);
		defPRINTF("[ERROR!]...Student Addition...FAILED!\n");
	} else {
		defPRINTF("Enter The Student's Data...\n\n");
		getRN(&temp);

		for (i = 0; i < FIFO_Buff_Students.length; i++) {
			if (Students[i].RollNum == temp) {
				defPRINTF("The Roll number you entered is already used!\n\n");
				defPRINTF("[ERROR!]...Student Addition...FAILED!\n");
				break;
			}
		}

		if (i == FIFO_Buff_Students.length) {
			NewStudent.RollNum = temp;

			getFName(&NewStudent);

			getLName(&NewStudent);

			getGPA(&NewStudent);

			defPRINTF("\tRegistered Courses[Max. = %d] :-\n", MaxCourses);

			for (j = 0; j < MaxCourses; j++) {
				getCid(&NewStudent, j);
				if (!(j == ((unsigned int) MaxCourses - 1))) {
					NewStudent.CourseID[j + 1] = 0;
					defPRINTF("\tEnter another course?	yes = 1...no = 0 : ");
					scanf("%u", &a);
					if (a == 0) {
						break;
					}
				}
			}

			STATUS = FIFO_Buff_push(&FIFO_Buff_Students, &NewStudent);

			if (STATUS == FIFO_Buff_No_Error) {
				G_count++;
			}
		}

	}
}



/*Find students by Their Roll Numbers and Print them*/
void find_RN() {
	unsigned int f = 0, j, count = FIFO_Buff_Students.length;
	data_type temp, *CurrentStudent = FIFO_Buff_Students.tail;

	defPRINTF("\nEnter The Roll Number of the student you want to find...\n");
	getRN(&temp.RollNum);

	if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		/*Iterate through the elements and print them*/
		while (count > 0) {
			if (CurrentStudent->RollNum == temp.RollNum) {
				defPRINTF("[INFO!]...Roll Number Found!..\n");
				defPRINTF("\tRoll Number : %u\n", CurrentStudent->RollNum);
				defPRINTF("\tFirst Name  : %s\n", CurrentStudent->FName);
				defPRINTF("\tLast Name   : %s\n", CurrentStudent->LName);
				defPRINTF("\tGPA : %.3f\n", CurrentStudent->GPA);

				defPRINTF("\tRegistered Courses[Max. = %d] :-\n", MaxCourses);
				for (j = 0; j < MaxCourses; j++) {
					defPRINTF("\tCourse %u ID : %u\n", j + 1,
							CurrentStudent->CourseID[j]);
					if (j == MaxCourses - 1) {
						break;
					} else if (!(CurrentStudent->CourseID[j + 1])) {
						break;
					}
				}

				f++;
				break;
			}

			if (CurrentStudent
					== ((FIFO_Buff_Students.base)
							+ (FIFO_Buff_Students.length) * sizeof(data_type))) {
				CurrentStudent = FIFO_Buff_Students.base;
			} else if (count == 1) {
				break;
			} else {
				CurrentStudent++;
			}

			count--;
		}

		if (f == 0) {
			defPRINTF("[INFO!]...Roll Number Not Found!\n\n");
		}

	}
}



/*Find students by Their First Names and Print them*/
void find_FN() {
	unsigned int f = 0, j, count = FIFO_Buff_Students.length;
	data_type temp, *CurrentStudent = FIFO_Buff_Students.tail;

	defPRINTF("\nEnter The First Name of the student you want to find...\n");
	getFName(&temp);

	if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		/*Iterate through the elements and print them*/
		while (count > 0) {
			if (strcmp(CurrentStudent->FName, temp.FName) == 0) {
				defPRINTF("[INFO!]...First Name Found!..\n");
				defPRINTF("Roll Number : %u\n", CurrentStudent->RollNum);
				defPRINTF("First Name  : %s\n", CurrentStudent->FName);
				defPRINTF("Last Name   : %s\n", CurrentStudent->LName);
				defPRINTF("GPA : %.3f\n", CurrentStudent->GPA);

				defPRINTF("\tRegistered Courses[Max. = %d] :-\n", MaxCourses);
				for (j = 0; j < MaxCourses; j++) {
					defPRINTF("\tCourse %u ID : %u\n", j + 1,
							CurrentStudent->CourseID[j]);
					if (j == MaxCourses - 1) {
						break;
					} else if (!(CurrentStudent->CourseID[j + 1])) {
						break;
					}
				}

				f++;
			}

			if (CurrentStudent
					== ((FIFO_Buff_Students.base)
							+ (FIFO_Buff_Students.length) * sizeof(data_type))) {
				CurrentStudent = FIFO_Buff_Students.base;
			} else if ((count == 1) && (f != 0)) {
				defPRINTF("[INFO!]...'%u' student(s) Found!\n\n", f);
				break;
			} else if (count == 1) {
				break;
			} else {
				CurrentStudent++;
			}

			count--;
		}

		if (f == 0) {
			defPRINTF("[INFO!]...First Name Not Found!\n\n");
		}
	}
}



/*Find and Print All the students who registered a certain course*/
void find_course() {
	unsigned int f = 0, j, count = FIFO_Buff_Students.length;
	data_type temp, *CurrentStudent = FIFO_Buff_Students.tail;

	defPRINTF(
			"\nEnter The Course ID to find the students who registered it...\n");
	getCid(&temp, (unsigned int) 0);

	if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		/*Iterate through the elements and print them*/
		while (count > 0) {
			for (j = 0; j < MaxCourses; j++) {
				if (CurrentStudent->CourseID[j] == temp.CourseID[0]) {
					defPRINTF("[INFO!]...Course ID Found!..\n");
					defPRINTF("\tRoll Number : %u\n", CurrentStudent->RollNum);
					defPRINTF("\tFirst Name  : %s\n", CurrentStudent->FName);
					defPRINTF("\tLast Name   : %s\n", CurrentStudent->LName);
					defPRINTF("\tGPA : %.3f\n", CurrentStudent->GPA);

					defPRINTF("\tRegistered Courses[Max. = %d] :-\n",
							MaxCourses);
					for (j = 0; j < MaxCourses; j++) {
						defPRINTF("\tCourse %u ID : %u\n", j + 1,
								CurrentStudent->CourseID[j]);
						if (j == MaxCourses - 1) {
							break;
						} else if (!(CurrentStudent->CourseID[j + 1])) {
							break;
						}
					}

					f++;
					defPRINTF("\n");
					break;
				}
			}

			if (CurrentStudent
					== ((FIFO_Buff_Students.base)
							+ (FIFO_Buff_Students.length) * sizeof(data_type))) {
				CurrentStudent = FIFO_Buff_Students.base;
			} else if ((count == 1) && (f != 0)) {
				defPRINTF("[INFO!]...'%u' student(s) Found!\n\n", f);
				break;
			} else if (count == 1) {
				break;
			} else {
				CurrentStudent++;
			}

			count--;
		}

		if (f == 0) {
			defPRINTF(
					"[INFO!]...The Course Is Not registered by any student!\n\n");
		}

	}
}



/*Print The Total Number of students in The Database*/
void tot_st() {
	if (!(FIFO_Buff_Students.base)) {
		defPRINTF("[ERROR!]...Database does not exist!!!\n\n");
	} else if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		defPRINTF(
				"[INFO!]...The total number of students in The Database is : %u\n",
				FIFO_Buff_Students.count);
		defPRINTF(
				"[INFO!]...You can add '%u' more students in The Database!\n\n",
				(FIFO_Buff_Students.length - FIFO_Buff_Students.count));
	}
}



/*Find students by Their Roll Numbers and Delete them*/
void del_st() {
	unsigned int f = 0, j, count = FIFO_Buff_Students.length;
	data_type temp, *CurrentStudent = FIFO_Buff_Students.tail;

	defPRINTF("\nEnter The Roll Number of the student you want to delete...\n");
	getRN(&temp.RollNum);

	if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		/*Iterate through the elements to delete the specified Roll Number*/
		while (count > 0) {
			if (CurrentStudent->RollNum == temp.RollNum) {
				CurrentStudent->RollNum = (unsigned int) 64799;
				strcpy(CurrentStudent->FName, "");
				strcpy(CurrentStudent->LName, "");
				CurrentStudent->GPA = 0.00000;

				for (j = 0; j < MaxCourses; j++) {
					CurrentStudent->CourseID[j] = (unsigned int) 0;
					if (j == MaxCourses - 1) {
						break;
					} else if (!(CurrentStudent->CourseID[j + 1])) {
						break;
					}
				}

				f++;
				FIFO_Buff_Students.count--;
				defPRINTF("[INFO!]...Roll Number Was Deleted Successfully!\n");
				break;
			}

			if (CurrentStudent
					== ((FIFO_Buff_Students.base)
							+ (FIFO_Buff_Students.length) * sizeof(data_type))) {
				CurrentStudent = FIFO_Buff_Students.base;
			} else if (count == 1) {
				break;
			} else {
				CurrentStudent++;
			}

			count--;
		}

		if (f == 0) {
			defPRINTF("[INFO!]...Roll Number Not Found!\n\n");
		}

	}
}



/*Find students by Their Roll Numbers and Update them*/
void upd_st() {
	unsigned int f = 0, i, j, a, tempRN, count = FIFO_Buff_Students.length;
	data_type temp, *CurrentStudent = FIFO_Buff_Students.tail, *CheckRN;
	char temp_text[10] = { 1 };

	defPRINTF("\nEnter The Roll Number of the student you want to update...\n");
	getRN(&temp.RollNum);

	if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		/*Iterate through the elements and print them*/
		while (count > 0) {
			if (CurrentStudent->RollNum == temp.RollNum) {
				defPRINTF("[INFO!]...[Roll Number Found!]..\n");
				defPRINTF("\tRoll Number : %u\n", CurrentStudent->RollNum);
				defPRINTF("\tFirst Name  : %s\n", CurrentStudent->FName);
				defPRINTF("\tLast Name   : %s\n", CurrentStudent->LName);
				defPRINTF("\tGPA : %.3f\n", CurrentStudent->GPA);

				defPRINTF("\tRegistered Courses[Max. = %d] :-\n", MaxCourses);
				for (j = 0; j < MaxCourses; j++) {
					defPRINTF("\tCourse %u ID : %u\n", j + 1,
							CurrentStudent->CourseID[j]);
					if (j == MaxCourses - 1) {
						break;
					} else if (!(CurrentStudent->CourseID[j + 1])) {
						break;
					}
				}

				f++;
				break;
			}

			if (CurrentStudent
					== ((FIFO_Buff_Students.base)
							+ (FIFO_Buff_Students.length) * sizeof(data_type))) {
				CurrentStudent = FIFO_Buff_Students.base;
			} else if (count == 1) {
				break;
			} else {
				CurrentStudent++;
			}

			count--;
		}

		if (f == 0) {
			defPRINTF("[INFO!]...Roll Number Not Found!\n\n");
		} else {
			while (atoi(temp_text) != 6) {
				defPRINTF(" \n===================================");
				defPRINTF(" \n\t Choose a field to update/edit...\n");
				defPRINTF(" \n 1 : First Name");
				defPRINTF(" \n 2 : Last Name");
				defPRINTF(" \n 3 : Roll Number");
				defPRINTF(" \n 4 : GPA");
				defPRINTF(" \n 5 : Courses");
				defPRINTF(" \n 6: Exit");
				defPRINTF(" \n===================================\n\n");
				defPRINTF("Your Choice : ");

				fgets(temp_text, 10, stdin);
				defPRINTF("\n");
				switch (atoi(temp_text)) {
				case 1:
					updFName(CurrentStudent);
					break;
				case 2:
					updLName(CurrentStudent);
					break;
				case 3:
					CheckRN = FIFO_Buff_Students.tail;
					updRN(&tempRN);
					for (i = 0; i < FIFO_Buff_Students.length; i++) {
						if (CheckRN->RollNum == tempRN) {
							defPRINTF(
									"[ERROR!]...The Roll Number you entered is already used!\n\n");
							break;
						} else if (i == (FIFO_Buff_Students.length - 1)) {
							CurrentStudent->RollNum = tempRN;
							defPRINTF(
									"[INFO!]...Roll Number Updated Successfully!\n\n");
							break;
						}
						if (CheckRN
								== ((FIFO_Buff_Students.base)
										+ (FIFO_Buff_Students.length)
												* sizeof(data_type))) {
							CheckRN = FIFO_Buff_Students.base;
						} else {
							CheckRN++;
						}
					}

					break;
				case 4:
					updGPA(CurrentStudent);
					break;
				case 5:
					for (j = 0; j < MaxCourses; j++) {
						updCid(CurrentStudent, j);
						if (!(j == ((unsigned int) MaxCourses - 1))) {
							CurrentStudent->CourseID[j + 1] = 0;
							defPRINTF(
									"\tEnter another course?	yes = 1...no = 0 : ");
							scanf("%u", &a);
							if (a == 0) {
								break;
							}
						}
					}

					defPRINTF("[INFO!]...Courses Updated Successfully!\n\n")
					;
					break;
				case 6:
					break;
				default:
					defPRINTF("Invalid Choice!!")
					;
					break;
				}
			}

		}
	}
}



/*Print All the students in The Database*/
void show_st() {
	if (!(FIFO_Buff_Students.base)) {
		defPRINTF("[ERROR!]...Database does not exist!!!\n\n");
	} else if (!(FIFO_Buff_Students.count)) {
		defPRINTF("[INFO!]...The students list is empty!!!\n\n");
	} else {
		FIFO_Buff_print(&FIFO_Buff_Students);
	}
}
