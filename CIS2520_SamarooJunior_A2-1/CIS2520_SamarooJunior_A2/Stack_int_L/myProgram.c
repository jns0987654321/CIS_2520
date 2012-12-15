/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student Stack implementations.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). The use of such a file was not required,
 *        but is very practical.
 *********************************************************************/


#include "StackInterface.h"
#include <stdio.h>
#include <stdlib.h>


static void showStackSize (Stack *L) 
{
	if(Empty(L)) printf("Stack is empty; ");
	else printf("Stack is not empty; ");
	if(Full(L)) printf("stack is full; ");
	else printf("stack is not full; ");
	printf("stack is of length %d:\n",Length(L));
}
	
	
static void showStackContent (Stack *L) 
{
    StackNode *temp;
    temp = NULL;
    temp = L->first;
    
    //Loop to print items of stack (the addition result)
    while (temp != NULL) 
    {
        printf("%d", temp->item);
        temp = temp->next; //transverse stack
    }
    printf("\n");
}

static void addNumbers(Stack *first, Stack *second, Stack *Sum)
{
    StackNode *numStackOne = NULL;
    StackNode *numStackTwo = NULL;
    int carry = 0;
    
    numStackOne = first->first; //head of 1st number
    numStackTwo = second->first; //head of 2nd number
    
    while (numStackOne != NULL) 
    {
        int tempNum, toAdd;
        if (numStackTwo != NULL) 
        {
            tempNum = numStackTwo->item + numStackOne->item; //adds numbers of stacks
            tempNum = tempNum + carry;
            if (tempNum > 9)
            {
                //calculates carry and remainder
                tempNum = tempNum % 10;
                toAdd = tempNum;
                carry = 1;
            }else{
                //no carry
                toAdd = tempNum;
                carry = 0;
            }
            numStackTwo = numStackTwo->next; //increments 2nd number
        }else{
            toAdd = numStackOne->item + carry;
            carry = 0;
        }
        numStackOne = numStackOne->next; //increments 1st number
        Push(toAdd,Sum); //adds sum to 3rd stack
    }
    
}

static void createStacks(Stack *first, Stack *second, FILE *test)
{
    char c; //temporarily stores each digit
    int num; //stores number to push on stack
    
    do {
        c = fgetc(test); //gets single char from text file        
            if (c !='\n') //check for end of line
            {
                num = atoi(&c);
    			Push(num,first); //pushes number on stack
            }  
        } while (c != '\n');
    
    do{
        c = fgetc(test); //gets single char from text file        
            if (c != EOF) //check for end of file
            {
                num = atoi(&c); //converts char to an int
    			Push(num,second); //pushes 2nd number on stack
            } 
        } while (c != EOF);
}

int main(void) 
{
	FILE *test;
	Stack first, second, Sum; 
	
	Initialize(&first); //initializes stack for first number
    Initialize(&second); ////initializes stack for second number
    Initialize(&Sum); //initializes stack for sum

    if ((test=fopen("test.txt","r")) == NULL){
        printf("ERROR OPENING FILE!!\n");
        exit(1);
    }
    
    //creates the stack of numbers to be added
    createStacks(&first, &second, test);
    fclose(test);
    
    //adds the two stack of numbers and stores sum in a third stack
    addNumbers(&first, &second, &Sum);
    printf("Addition Result is: \n");
    showStackContent(&Sum);	
	Destroy(&first);
    
	return EXIT_SUCCESS;
}

