/*
 *  main.c
 *
 *  Created on: Jan 11, 2024
 *      Author: Mina
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LinkedList_APIs.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}



int main() {
	char temp_text[10] = { 1 };
	defPRINTF("<<<<< Welcome To The Student Management System >>>>>\n");

	while (atoi(temp_text) != 12) {
		defPRINTF("\n======================================\n");
		defPRINTF("Choose one of the following options...");
		defPRINTF("\n 1 : Add a Student");
		defPRINTF("\n 2 : Delete a Student");
		defPRINTF("\n 3 : View All");
		defPRINTF("\n 4 : Delete All");
		defPRINTF("\n 5 : View a student(List Number is required)");
		defPRINTF("\n 6 : Total Number of students(Iterative Method)");
		defPRINTF("\n 7 : Total Number of students(Recursive Method)");
		defPRINTF("\n 8 : View a student(Number from The List End is required)");
		defPRINTF("\n 9 : View the List-Middle Student");
		defPRINTF("\n 10: Detect if a Loop Exists");
		defPRINTF("\n 11: Reverse The Order of The Linked List");
		defPRINTF("\n 12: Exit");
		defPRINTF("\n======================================\n\n");
		defPRINTF("Your Choice : ");

		fgets(temp_text, 10, stdin);
		switch (atoi(temp_text)) {
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			ShowEntireList();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			GetNth();
			break;
		case 6:
			GetLength_iterative();
			break;
		case 7:
			PrintLength_recursive();
			break;
		case 8:
			GetNthFromTheEnd();
			break;
		case 9:
			GetTheMiddleNode();
			break;
		case 10:
			DetectLoop();
			break;
		case 11:
			ReverseLinkedList();
			break;
		case 12:
			break;
		default:
			defPRINTF("Invalid Choice!!\n")
			;
			break;
		}
	}

	return 0;
}
