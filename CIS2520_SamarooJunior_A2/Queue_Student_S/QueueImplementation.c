/*********************************************************************
 * FILE NAME: QueueImplementation.c
 * PURPOSE: Sequential implementation of the Student Queue ADT.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only these static functions will need to be modified
 *          if the type of the queue items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the Queue ADT changes.
 *        . As we will see, there is a better way to check whether
 *          the preconditions and postconditions are met.
 *********************************************************************/


#include "QueueInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void copyItem (Item *Y, Item X) 
{
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X) 
{
	FreeStudent(X);
}


static int equalItems (Item X, Item Y) 
{
	/* Why couldn't we write the following?
	   if(strcmp(NameOfStudent(X),NameOfStudent(Y))!=0 ||
	      GradeOfStudent(X)!=GradeOfStudent(Y)) return 0;
	   else return 1; */
	int i;
	char *s;
	s=(char *)malloc(strlen(NameOfStudent(X))+1);
	strcpy(s,NameOfStudent(X));
	i=strcmp(s,NameOfStudent(Y));
	free(s);
	if(i!=0 || GradeOfStudent(X)!=GradeOfStudent(Y)) return 0;
	else return 1;
}


void Initialize (Queue *L) 
{
	L->size = 0;
    L->head = 0;
#ifdef DEBUG
	if(!Empty(L) || Full(L) || Length(L)!=0) {
		printf("Violated postcondition for Initialize!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Enqueue (Item X, Queue *L) 
{
    //finds correct position to insert in array
	copyItem(&L->items[(Length(L) + L->head) % (MAXLISTSIZE)],X);
	L->size++; 
}


void Dequeue (Queue *L) {
#ifdef DEBUG
	int oldLength=Length(L);
#endif
	destroyItem(&L->items[L->head]);
    L->head++; //increments head of queue
    L->size--; //decreases size of queue
#ifdef DEBUG
	if(Full(L) || Length(L)!=oldLength-1) {
		printf("Violated postcondition for Delete!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


int Full (Queue *L) 
{
	return L->size==MAXLISTSIZE;
}


int Empty (Queue *L) 
{
	return L->size==0;
}


int Length (Queue *L) 
{
	return L->size;
}


void Head (Queue *L, Item *X) 
{
    //gets head of queue
	copyItem(X,L->items[L->head]);
}


void Destroy (Queue *L) 
{
	int i;
	for(i=0;i<MAXLISTSIZE;i++) //destroys enitre array
		destroyItem(&L->items[i]);
}

