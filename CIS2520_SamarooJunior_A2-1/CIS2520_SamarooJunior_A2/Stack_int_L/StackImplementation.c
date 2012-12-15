/*********************************************************************
 * FILE NAME: StackImplementation.c
 * PURPOSE: One-way linked implementation of the Student Stack ADT.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: . Some functions are static (they are auxiliary functions
 *          with local scope; they are not visible outside the file).
 *        . Only the first two functions will need to be modified
 *          if the type of the stack items (here, Student) changes. 
 *        . Only the other functions will need to be modified if
 *          the implementation of the Stack ADT changes.
 *        . For preconditions and postconditions,
 *          see the sequential implementation.
 *********************************************************************/


#include "StackInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static void copyItem (Item *Y, Item X) 
{
	return;
}


static void destroyItem (Item *X) 
{
	return;
}


static StackNode *moveTo (int position, Stack *L) 
{
	int i;
	StackNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}


void Initialize (Stack *L) 
{
	L->size=0;
	L->first=NULL;
}


void Push (Item X, Stack *L) 
{
    StackNode *q;
    
	L->size++; //increment stack size
	q=(StackNode *)malloc(sizeof(StackNode));
    q->item = X;
    q->next = L->first;
    L->first = q; //adds item to top of stack
}


void Pop (Stack *L) 
{
    assert(L != NULL);
    StackNode *tempNode; //item to be popped
    Item tempItem;

    Top(L, &tempItem); //gets top of stack
    tempNode = L->first;
    L->first = L->first->next;
	free(tempNode); //frees item at top of stack
	L->size--; //decrement stack size
}


int Full (Stack *L) 
{
	return L->size;
}


int Empty (Stack *L) 
{
	return L->size==0;
}


int Length (Stack *L) 
{
	return L->size;
}


void Top (Stack *L, Item *X) 
{
    *X = L->first->item; //returns item at top of stack
}

void Destroy (Stack *L) 
{
	int i;
	StackNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyItem(&q->item);
		free(q);
	}
}

void Reverse (Stack *L) 
{
    assert(L != NULL); //precondition for empty list
    
    StackNode *head, *remainder;
    Stack tempRest; //temporary list for recursion function
    
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

