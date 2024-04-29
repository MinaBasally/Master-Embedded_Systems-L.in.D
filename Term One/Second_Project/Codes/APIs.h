/*
 *  APIs.h
 *
 *  Created on: Feb 1, 2024
 *      Author: Mina
 *
 */

#ifndef APIS_H_
#define APIS_H_

#include "FIFO.h"
#include "stdio.h"



/*APIs Prototypes*/
void add_student_from_file();
void add_student_manually();
void find_RN();
void find_FN();
void find_course();
void tot_st();
void del_st();
void upd_st();
void show_st();
void getFName(data_type *CS);
void getLName(data_type *CS);
void getGPA(data_type *CS);
void getRN(unsigned int *temp);
void getCid(data_type *CS, unsigned int j);
void updFName(data_type *CS);
void updLName(data_type *CS);
void updGPA(data_type *CS);
void updRN(unsigned int *temp);
void updCid(data_type *CS, unsigned int j);



#endif /* APIS_H_ */
