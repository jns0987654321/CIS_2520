/*********************************************************************
 * FILE NAME: StackType.h
 * PURPOSE: Concrete data structure definition of Student Stack.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: A limit (MAXLISTSIZE) has been set to the number of items
 *        of a Student Stack only so that the output of the test
 *        program does not change (as required in Question 4).
 *********************************************************************/


typedef int Item;

typedef struct StackNodeTag {
	Item item;
	struct StackNodeTag *next;
} StackNode;

typedef struct {
	int size;
	StackNode *first;
} Stack;