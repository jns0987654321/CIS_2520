/*********************************************************************
 * FILE NAME: ListImplementation.c
 * PURPOSE: One-way linked implementation of the Student List ADT.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only the first two functions will need to be modified
 *          if the type of the list items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the List ADT changes.
 *        . For preconditions and postconditions,
 *          see the sequential implementation.
 *********************************************************************/


#include "ListInterface.h"
#include <stdlib.h>
#include <assert.h>

static void copyItem (Item *Y, Item X) {
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}


static void destroyItem (Item *X) {
	FreeStudent(X);
}


static ListNode *moveTo (int position, List *L) {
    
	int i;
	ListNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}

void Initialize (List *L) {
    
	L->size=0;
	L->first=NULL;
    
    assert(Empty(L));
    assert(!Full(L));
    assert(Length(L) == 0);
}

void Insert (Item X, int position, List *L) {
    
    assert(position >= 0 );
    assert(position <= Length(L));
    assert(!Full(L));

	ListNode *p, *q;
	int oldLength = Length(L);
	L->size++;
	q=(ListNode *)malloc(sizeof(ListNode));
	copyItem(&q->item,X);
			 
	if(position==0) {
		q->next=L->first;
		L->first=q;
	}
	else {
		p=moveTo(position-1,L);
		q->next=p->next;
		p->next=q;
	}
    
    Item peekTemp;
    Peek(position, L, &peekTemp);
    
    assert(!Empty(L));
    assert(Length(L) == oldLength+1);
    assert(X.grade == peekTemp.grade);
    assert(!strcmp(X.name, peekTemp.name));
}

void Delete (int position, List *L) {
    
    assert(position >= 0 );
    assert(position <= Length(L));
    assert(Length(L) > 0);
    
	ListNode *p, *q;
    
    int oldLength = Length(L);
	
	if(position==0) {
		q=L->first;
		L->first=q->next;
	}
	else {
		p=moveTo(position-1,L);
		q=p->next;
		p->next=q->next;
	}
	
	destroyItem(&q->item);
	free(q);
	L->size--;
    
    assert(!Full(L));
    assert(Length(L) == oldLength-1);
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
    
    assert(position >= 0 );
    assert(position <= Length(L));
    assert(Length(L) > 0);

	ListNode *p;
	p=moveTo(position,L);
	copyItem(X,p->item);
}


void Destroy (List *L) {
    
	int i;
	ListNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyItem(&q->item);
		free(q);
	}
}

void Reverse (List *L) {
    assert(L != NULL); //precondition for empty list
    
    ListNode *head, *remainder;
    List tempRest; //temporary list for recursion function
    
    head = L->first;
    remainder = head->next; //rest of list to be reversed
    if (remainder == NULL)
        return;
    tempRest.first = remainder;
    
    Reverse(&tempRest); //calls itself with remainder of list
    
    head->next->next = head;
    head->next = NULL;    
    L->first = tempRest.first; //attaches head
}

