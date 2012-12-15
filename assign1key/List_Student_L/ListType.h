/*********************************************************************
 * FILE NAME: ListType.h
 * PURPOSE: Concrete data structure definition of Student List.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: A limit (MAXLISTSIZE) has been set to the number of items
 *        of a Student List only so that the output of the test
 *        program does not change (as required in Question 4).
 *********************************************************************/


#include "StudentInterface.h"
typedef Student Item;


#define MAXLISTSIZE 4

typedef struct ListNodeTag {
	Item item;
	struct ListNodeTag *next;
} ListNode;

typedef struct {
	int size;
	ListNode *first;
} List;