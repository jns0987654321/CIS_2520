/*******************************************************************
 * AUTHOR: Junior Samaroo
 * DATE: November 12th, 2011
 * Assignment #3 CIS2520 Part B
 *
 * myProgram.c: Creates a Binary tree with data stored in test.txt
 *              and sorts them according to grades.
 *
 ******************************************************************/

#include "StudentInterface.h"
#include "TreeInterface.h"
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void displayTree(Tree *X);
int compareItems (void *X, void *Y);
void destroyItem (void *X);
void *copyItem (void *Y, void *X);

/* Main Function */
int main (void) 
{
    FILE *fp;
    char name[20]; //name buffer
    int grade;      
    Student boyGirl;    //Student to be inserted
    Tree class;         //Binary tree
    
    Initialize(&class, *(&copyItem), (&destroyItem), (&compareItems));
    fp = fopen("test.txt", "r");
    if (fp == NULL) 
    {
        printf("Error opening file!!\n");
        exit(0);
    }
    
    /* While loop that reads data from test.txt and inserts it 
     * into the binary tree.
     */ 
    while (fscanf(fp, "%s %d",name ,&grade) == 2) 
    {
        InitializeStudent(name, grade, &boyGirl);
        Insert(&class, &boyGirl);
    }

    displayTree(&class);    //Displays tree contents in terminal
    Destroy(&class);        //Deletes the binary tree

    fclose(fp);

    return 0;
    
}

/* Function to print students from binary tree
 * according to grades from lowest to highest.
 */
void displayTree(Tree *class)
{
    Student temp;
    
    //Prints miimum grade
    if(Minimum(class, &temp))
    {
        printf("%-15s %d%%\n", NameOfStudent(temp), GradeOfStudent(temp));
    }else{
        printf("Tree is empty!!\n");
        exit(1);
    }
    
    //Prints minimum grade successors
    while (Successor(class, &temp)) {
        printf("%-15s %d%%\n", NameOfStudent(temp),GradeOfStudent(temp));
    }
    
}

/* -------------------------------------------------
*  . A copy function
*  ------------------------------------------------- 
*  PURPOSE: Makes a copy of an item.
*  ARGUMENTS: . NULL, or the address (void *) of  
*               the location in memory where the 
*               copy must be stored
*             . The address (void *) of the item 
*               to be copied
*  RETURNS: The address (void *) of the location in
*           memory where the copy has been stored
*  NOTES: If the first argument is NULL, the copy
*         function allocates memory for the copy,
*         and this memory should later be freed
*         by the destroy function below.
*  -------------------------------------------------- 
*/
void *copyItem (void *Y, void *X) 
{
    Student *temp;
    temp = (Student*)X;
    
    if (Y == NULL)
    {
        //Allocates memory if 1st argument is null
        Y = malloc(sizeof(Student));
        InitializeStudent(NameOfStudent(*temp),GradeOfStudent(*temp),Y);
        return Y;
    }else{
        InitializeStudent(NameOfStudent(*temp),GradeOfStudent(*temp),Y);
        return Y;
    }
    
}

/* --------------------------------------------------
*  . A destroy function
*  --------------------------------------------------
*  PURPOSE: Frees memory that may have been 
*           allocated by the copy function above.
*  ARGUMENT: The address of the item to be destroyed
*            (void *); this address must have been
*            returned by the copy function called
*            with NULL as its first argument
*  --------------------------------------------------
*/
void destroyItem (void *X) 
{
    Student *temp;
    temp = (Student*)X;
	FreeStudent(temp);
}

/* ------------------------------------------------------
*  . A compare function
*  ------------------------------------------------------
*  PURPOSE: Compares two items.
*  ARGUMENTS: . A pointer to a first item (void *)
*             . A pointer to a second item (void *)
*  RETURNS: The integer
*           -1 if the 1st item is less than the 2nd item,
*           0 if the two items are equal,
*           1 otherwise
*  -------------------------------------------------------
*/
int compareItems (void *X, void *Y) 
{
    Student *first, *second;
    first = (Student*)X;
    second = (Student*)Y;
        
    if (GradeOfStudent(*first) < GradeOfStudent(*second)) 
    {
        return -1; //1st item is less than the 2nd item
    }
    else if (GradeOfStudent(*first) == GradeOfStudent(*second)) 
        return 0; //two items are equal
    else
        return 1; //otherwise
    
}



