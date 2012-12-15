/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student Queue implementations.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). The use of such a file was not required,
 *        but is very practical.
 *********************************************************************/


#include "QueueInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void showQueueSize (Queue *L) 
{
	if(Empty(L)) printf("Queue is empty; ");
	else printf("Queue is not empty; ");
	if(Full(L)) printf("queue is full; ");
	else printf("queue is not full; ");
	printf("queue is of length %d:\n",Length(L));
}
	
	
static void showQueueContent (Queue *L) 
{
	int i;
	Student S;
    int realHead = L->head;
    //loop transverses through queue via head
	for(i=0;i<Length(L);i++) 
    {
        //circulates array if maxsize is reached
        if (L->head == MAXLISTSIZE)  
        {
            L->head = 0;
        }
		Head(L,&S); //gets head of queue
		printf("\t%s %d%%\n",NameOfStudent(S),GradeOfStudent(S));
		FreeStudent(&S);
        L->head++;   
	}
    L->head = realHead; //fixes the head
}
	

int main(void) 
{
	FILE *test;
	char s[20];
	int grade;
	
	Student S;
	Queue Q; 
	
	Initialize(&Q);
	showQueueSize(&Q);
	showQueueContent(&Q);
	
	test=fopen("test.txt","r");
    //loop checks for a command in txt file either "Insert" or "Delete"
	while(fscanf(test,"%s",s)==1) 
    {
		if(strcmp(s,"Insert")==0) 
        {
			fscanf(test,"%s %d",s,&grade);
			InitializeStudent(s,grade,&S);
			Enqueue(S,&Q); //adds student from the text file
			FreeStudent(&S);
		}
		if(strcmp(s,"Delete")==0)
			Dequeue(&Q); //deletes student from queue
		showQueueSize(&Q);
		showQueueContent(&Q);
	}
	
	fclose(test);
	Destroy(&Q);
	return EXIT_SUCCESS;
}

