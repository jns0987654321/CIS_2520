/*********************************************************************
 * FILE NAME: StackInterface.h
 * PURPOSE: Interface of the Student Stack ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: . If the user includes StackInterface.h in a source file,
 *          they should not include StudentInterface.h. Including 
 *          both header files in the same source file would cause 
 *          a compilation error, because StackInterface.h indirectly 
 *          includes StudentInterface.h, and the type Student would 
 *          therefore be defined twice. (As we will see, however,  
 *          there is a way to go around this.)
 *        . Peek calls InitializeStudent, and it is the user's
 *          responsibility to call FreeStudent when appropriate
 *          (see StudentInterface.h).
 *        . In the following,
 *          the word Item may be replaced by the word Student.
 *********************************************************************/
#include "StackType.h"

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a Stack variable to the empty Stack.
 * ARGUMENTS: The address of the Stack variable to be initialized
 *            (Stack *) 
 * ENSURES: . Empty will return true (a nonzero integer).
 *          . Full will return false (0).
 *          . Length will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Stack variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Insert
 * PURPOSE: Inserts an Item in a Stack.
 * ARGUMENTS: . The Item to be inserted (Item)
 *            . The position in the Stack
 *              where the Item should be inserted in (int) 
 *            . The address of the Stack (Stack *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             not greater than the length of the Stack.
 *           . The Stack should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Length will return the first integer greater
 *            than the length of the Stack before the call.
 *          . Peek in the same position will find
 *            the Item that was inserted.
 *********************************************************************/
extern void Push (Item X, Stack *S);

/*********************************************************************
 * FUNCTION NAME: Delete
 * PURPOSE: Deletes an Item from a Stack.
 * ARGUMENTS: . The position in the Stack
 *              where the Item to be deleted is in (int) 
 *            . The address of the Stack (Stack *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the Stack.
 *           . The Stack should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Length will return the first integer lower
 *            than the length of the Stack before the call.
 *********************************************************************/
extern void Pop (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Full
 * PURPOSE: Determines whether a Stack is full.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: True (a nonzero integer) if the Stack is full,
 *          false (0) otherwise
 *********************************************************************/
extern int Full (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Empty
 * PURPOSE: Determines whether a Stack is empty.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: True (a nonzero integer) if the Stack is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int Empty (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Length
 * PURPOSE: Finds the size of a Stack.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: The size of the Stack (int)
 *********************************************************************/
extern int Length (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Peek
 * PURPOSE: Finds an Item in a Stack.
 * ARGUMENTS: . The position in the Stack where the Item is in (int) 
 *            . The address of the Stack (Stack *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the Stack.
 *           . The Stack should not be empty.
 *********************************************************************/
extern void Top (Stack *S, Item *X);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Delete.
 * ARGUMENTS: The address of the Stack to be destroyed (Stack *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void Destroy (Stack *S);

/*********************************************************************
 * FUNCTION NAME: Reverse
 * PURPOSE: Reverses a Stack
 (the first Item becomes the last and vice versa).
 * ARGUMENTS: The address of the Stack to be reversed (Stack *) 
 *********************************************************************/
extern void Reverse (Stack *S);

