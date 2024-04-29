/*
 *  main.c
 *
 *  *A Student Management System Program*
 *
 *  Created on: Feb 1, 2024
 *      Author: Mina
 *
 */

#include "FIFO.h"
#include "APIs.h"
#include "stdio.h"
#include "stdlib.h"

#define length  entries
#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}



FIFO_t FIFO_Buff_Students;
data_type i, temp, Students[entries];



int main() {
	FIFO_Buff_init(&FIFO_Buff_Students, Students, length);


	char temp_text[10] = { 1 };
	defPRINTF("<<<<< Welcome To The Student Management System >>>>>\n");

	while (atoi(temp_text) != 10) {
		defPRINTF("\n===================================\n");
		defPRINTF("Choose one of the following options...\n");
		defPRINTF(" 1. Add A Student\n");
		defPRINTF(" 2. Add Student(s) From A File\n");
		defPRINTF(" 3. Find A Student By roll Number\n");
		defPRINTF(" 4. Find A Student By First Name\n");
		defPRINTF(" 5. Find A Student By Course ID\n");
		defPRINTF(" 6. Find The Total Number Of Students\n");
		defPRINTF(" 7. Delete A Student By Roll Number\n");
		defPRINTF(" 8. Update A Student By Roll Number\n");
		defPRINTF(" 9. Show All Students\n");
		defPRINTF(" 10. Exit\n");
		defPRINTF("===================================\n\n");
		defPRINTF("Your Choice : ");

		fgets(temp_text, 10, stdin);
		switch (atoi(temp_text)) {
		case 1:
			add_student_manually();
			break;
		case 2:
			add_student_from_file();
			break;
		case 3:
			find_RN();
			break;
		case 4:
			find_FN();
			break;
		case 5:
			find_course();
			break;
		case 6:
			tot_st();
			break;
		case 7:
			del_st();
			break;
		case 8:
			upd_st();
			break;
		case 9:
			show_st();
			break;
		case 10:
			break;
		default:
			defPRINTF("Invalid Choice!!\n")
			;
			break;
		}
	}

	return 0;
}
