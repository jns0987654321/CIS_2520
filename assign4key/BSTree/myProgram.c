/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for generic
 *          Binary Search Tree implementations
 * AUTHOR: P. Matsakis (CIS2520, Assignment 4)
 * DATE: 25/11/2011
 *********************************************************************/


#include "StudentInterface.h"
#include "TreeInterface.h"
#include <stdio.h>
#include <stdlib.h>


static void * copyStudent (void *Y, void *X) {
	if(Y==NULL) Y=malloc(sizeof(Student));
	InitializeStudent(NameOfStudent(*(Student*)X),
					  GradeOfStudent(*(Student*)X),
					  Y);	
	return Y;
}


static void destroyStudent (void *X) {
	FreeStudent(X);
	free(X); 
} 


static int compareStudents (void *X, void *Y) {
	int i, j;
	i=GradeOfStudent(*(Student*)X);
	j=GradeOfStudent(*(Student*)Y);
	if(i<j) return -1;
	else if(i==j) return 0;
	else return 1;
}


int main (void) {
	FILE *test;
	char name[20];
	int grade;
	Student S;
	Tree T; 
	
	Initialize(&T,copyStudent,destroyStudent,compareStudents);
	printf("Initialize()\n");
	printf("Size=%d, Height=%d, ",Size(&T),Height(&T));
	if(Balanced(&T)) printf("Balanced=YES\n\n");
	else printf("Balanced=NO\n\n");
	
	test=fopen("test.txt","r");
	while(fscanf(test,"%s %d",name,&grade)==2) {
		InitializeStudent(name,grade,&S);
		Insert(&T,&S);
		printf("Insert(%s,%d)\n",NameOfStudent(S),GradeOfStudent(S));
		printf("Size=%d, Height=%d, ",Size(&T),Height(&T));
		if(Balanced(&T)) printf("Balanced=YES\n\n");
		else printf("Balanced=NO\n\n");
		FreeStudent(&S);
	}
	fclose(test);
		
	Minimum(&T,&S);
	do {
		printf("%s\t%d%%\n",NameOfStudent(S),GradeOfStudent(S));
		FreeStudent(&S);
	}
	while(Successor(&T,&S));
	
	Destroy(&T);
	return EXIT_SUCCESS;
}

