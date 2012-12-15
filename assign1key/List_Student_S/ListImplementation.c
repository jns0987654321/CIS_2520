/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: Sequential implementation of the Student List ADT.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only these static functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . As we will see, there is a better way to check whether
 *          the preconditions and postconditions are met.
 *********************************************************************/


#include "ListInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define DEBUG


static void copyItem (Item *Y, Item X) {
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X) {
	FreeStudent(X);
}


static int equalItems (Item X, Item Y) {
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


void Initialize (List *L) {
	L->size=0;
#ifdef DEBUG
	if(!Empty(L) || Full(L) || Length(L)!=0) {
		printf("Violated postcondition for Initialize!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Insert (Item X, int position, List *L) {
#ifdef DEBUG
	int oldLength=Length(L);
	if(position<0 || position>oldLength || Full(L)) {
		printf("Violated precondition for Insert!\n");
		exit(EXIT_FAILURE);
	}
#endif
	int i;
	for (i=L->size; i>position; i--) { 
		copyItem(&L->items[i],L->items[i-1]);
		destroyItem(&L->items[i-1]);
	}
	copyItem(&L->items[position],X);
	L->size++;
#ifdef DEBUG
	Item Y;
	Peek(position,L,&Y);
	if(Empty(L) || Length(L)!=oldLength+1 || !equalItems(X,Y)) {
		printf("Violated postcondition for Insert!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


void Delete (int position, List *L) {
#ifdef DEBUG
	int oldLength=Length(L);
	if(position<0 || position>=oldLength || Empty(L)) {
		printf("Violated precondition for Delete!\n");
		exit(EXIT_FAILURE);
	}
#endif
	int i;
	L->size--;
	for (i=position; i<L->size; i++) {
		destroyItem(&L->items[i]);
		copyItem(&L->items[i],L->items[i+1]);
	}
	destroyItem(&L->items[L->size]);
#ifdef DEBUG
	if(Full(L) || Length(L)!=oldLength-1) {
		printf("Violated postcondition for Delete!\n");
		exit(EXIT_FAILURE);
	}
#endif
}


int Full (List *L) {
	return L->size==MAXLISTSIZE;
}


int Empty (List *L) {
	return L->size==0;
}


int Length (List *L) {
	return L->size;
}


void Peek (int position, List *L, Item *X) {
#ifdef DEBUG
	if(position<0 || position>=Length(L) || Empty(L)) {
		printf("Violated precondition for Peek!\n");
		exit(EXIT_FAILURE);
	}
#endif
	copyItem(X,L->items[position]);
}


void Destroy (List *L) {
	int i;
	for(i=0;i<L->size;i++)
		destroyItem(&L->items[i]);
}

