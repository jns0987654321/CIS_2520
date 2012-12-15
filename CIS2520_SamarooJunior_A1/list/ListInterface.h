/*****************************************************************
 * FILE NAME: ListInterface.h
 * PURPOSE: Provide a standard interface for List functions.
 * AUTHOR: Junior Samaroo
 * DATE: October 1st, 2011.
 * NOTES: This file is the same in the sequential and linked
 list implementations.
 ****************************************************************/
#include "ListType.h"
#include <stdio.h>
#include <stdlib.h>

/*****************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Preapares a list to insert and delete students.
 * ARGUMENTS: The list to be initialized of type "List"
 * RETURNS: Void function that retuns nothing.
 * REQUIRES: A list of type "List"
 * ENSURES: That the list functions can be used.
 * NOTES: 
 ****************************************************************/
extern void Initialize (List *L);

/*****************************************************************
 * FUNCTION NAME: Insert
 * PURPOSE: To insert a student in a list.
 * ARGUMENTS: Item X: The student to insert
 int position: The position in the list to insert
 List *L; The list in which to insert the student.
 * RETURNS: Void function that retuns nothing.
 * REQUIRES: An initialized list and a valid position in list.
 * ENSURES: That there are students in the list.
 * NOTES: Should only insert in a position less that size of list.
 ****************************************************************/
extern void Insert (Item X, int position, List *L); 

/*****************************************************************
 * FUNCTION NAME: Delete
 * PURPOSE: Deletes a student from a list
 * ARGUMENTS: int position: position in which to delete student.
 List *L: The list from which to delete the student.
 * RETURNS: Void function that retuns nothing.
 * REQUIRES: An initialized list and a valid position in list.
 * ENSURES: That there are students in the list.
 * NOTES: Should only delete in a position less that size of list.
 ****************************************************************/
extern void Delete (int position, List *L);

/*****************************************************************
 * FUNCTION NAME: Full
 * PURPOSE: To determine whether a list is full or not.
 * ARGUMENTS: The list to be analyzed.
 * RETURNS: 1 if true or 0 if false.
 * REQUIRES: An initialized list.
 * ENSURES: Ensures the list is not full.
 * NOTES: 
 ****************************************************************/
extern int Full (List *L);

/*****************************************************************
 * FUNCTION NAME: Empty
 * PURPOSE: To determine whether a list is empty or not.
 * ARGUMENTS: THe list to be analyzed.
 * RETURNS: 1 if true or 0 if false
 * REQUIRES: A list to be analyzed.
 * ENSURES: Ensures the list is not empty.
 * NOTES: 
 ****************************************************************/
extern int Empty (List *L);

/*****************************************************************
 * FUNCTION NAME: Length
 * PURPOSE: To determine the length of a list.
 * ARGUMENTS: The list to be analzed.
 * RETURNS: The length of the list as an int.
 * REQUIRES: A list to be analysed.
 * ENSURES: The length of the list is known.
 * NOTES: 
 ****************************************************************/
extern int Length (List *L);

/*****************************************************************
 * FUNCTION NAME: Peek
 * PURPOSE: To look at a student in a list
 * ARGUMENTS: int position: Position in list to look at.
 List *L: List to peek into.
 Item *X: Stores found student
 * RETURNS: Void function that retuns nothing.
 * REQUIRES: A list to peek into and a valid position.
 * ENSURES: That there is a student in the list.
 * NOTES: Should only peek in a position less that size of list.
 ****************************************************************/
extern void Peek (int position, List *L, Item *X); 

/*****************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: To delete a list of students.
 * ARGUMENTS: The list to be deleted.
 * RETURNS: Void function that retuns nothing.
 * REQUIRES: A list of students.
 * ENSURES: The list is empty.
 * NOTES: 
 ****************************************************************/
extern void Destroy (List *L);
