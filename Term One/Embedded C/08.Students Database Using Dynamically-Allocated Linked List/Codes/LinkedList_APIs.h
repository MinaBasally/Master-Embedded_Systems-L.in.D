/*
 *  LinkedList_APIs.h
 *
 *  Created on: Jan 11, 2024
 *      Author: Mina
 *
 */

#ifndef LINKEDLIST_APIS_H_
#define LINKEDLIST_APIS_H_

#include "stdio.h"
#define MaxNameLength 70



/*Structures Definitions*/
struct Sdate {
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
};

/*Nested Structures*/
struct Sdata {
	unsigned int ID;
	char Name[MaxNameLength];
	struct Sdate Birthdate;
	float Height;
};



/*Linked List Node*/
struct Sstudent {
	struct Sdata StudentData;
	struct Sstudent *PNextStudent;
};



/*APIs Prototypes*/
void AddStudent();
int DeleteStudent();
void ShowEntireList();
void DeleteAll();
void GetNth();
void GetLength_iterative();
unsigned int GetLength_recursive(struct Sstudent *PCurrentStudent);
void PrintLength_recursive();
void GetNthFromTheEnd();
void GetTheMiddleNode();
void DetectLoop();
void ReverseLinkedList();



#endif /* LINKEDLIST_APIS_H_ */
