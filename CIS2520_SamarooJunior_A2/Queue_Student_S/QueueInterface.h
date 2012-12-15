/*********************************************************************
 * FILE NAME: QueueInterface.h
 * PURPOSE: Interface of the Student Queue ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 1)
 * DATE: 30/09/2011
 * NOTES: . If the user includes QueueInterface.h in a source file,
 *          they should not include StudentInterface.h. Including 
 *          both header files in the same source file would cause 
 *          a compilation error, because QueueInterface.h indirectly 
 *          includes StudentInterface.h, and the type Student would 
 *          therefore be defined twice. (As we will see, however,  
 *          there is a way to go around this.)
 *        . Peek calls InitializeStudent, and it is the user's
 *          responsibility to call FreeStudent when appropriate
 *          (see StudentInterface.h).
 *        . In the following,
 *          the word Item may be replaced by the word Student.
 *********************************************************************/
#include "QueueType.h"

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a Queue variable to the empty Queue.
 * ARGUMENTS: The address of the Queue variable to be initialized
 *            (Queue *) 
 * ENSURES: . Empty will return true (a nonzero integer).
 *          . Full will return false (0).
 *          . Length will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Queue variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Queue *Q);

/*********************************************************************
 * FUNCTION NAME: Insert
 * PURPOSE: Inserts an Item in a Queue.
 * ARGUMENTS: . The Item to be inserted (Item)
 *            . The position in the Queue
 *              where the Item should be inserted in (int) 
 *            . The address of the Queue (Queue *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             not greater than the length of the Queue.
 *           . The Queue should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Length will return the first integer greater
 *            than the length of the Queue before the call.
 *          . Peek in the same position will find
 *            the Item that was inserted.
 *********************************************************************/
extern void Enqueue (Item X, Queue *Q);

/*********************************************************************
 * FUNCTION NAME: Delete
 * PURPOSE: Deletes an Item from a Queue.
 * ARGUMENTS: . The position in the Queue
 *              where the Item to be deleted is in (int) 
 *            . The address of the Queue (Queue *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the Queue.
 *           . The Queue should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Length will return the first integer lower
 *            than the length of the Queue before the call.
 *********************************************************************/
extern void Dequeue (Queue *Q);

/*********************************************************************
 * FUNCTION NAME: Full
 * PURPOSE: Determines whether a Queue is full.
 * ARGUMENTS: The address of the Queue (Queue *) 
 * RETURNS: True (a nonzero integer) if the Queue is full,
 *          false (0) otherwise
 *********************************************************************/
extern int Full (Queue *Q);

/*********************************************************************
 * FUNCTION NAME: Empty
 * PURPOSE: Determines whether a Queue is empty.
 * ARGUMENTS: The address of the Queue (Queue *) 
 * RETURNS: True (a nonzero integer) if the Queue is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int Empty (Queue *Q);

/*********************************************************************
 * FUNCTION NAME: Length
 * PURPOSE: Finds the size of a Queue.
 * ARGUMENTS: The address of the Queue (Queue *) 
 * RETURNS: The size of the Queue (int)
 *********************************************************************/
extern int Length (Queue *Q);

/*********************************************************************
 * FUNCTION NAME: Peek
 * PURPOSE: Finds an Item in a Queue.
 * ARGUMENTS: . The position in the Queue where the Item is in (int) 
 *            . The address of the Queue (Queue *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the Queue.
 *           . The Queue should not be empty.
 *********************************************************************/
extern void Head (Queue *Q, Item *X);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Delete.
 * ARGUMENTS: The address of the Queue to be destroyed (Queue *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void Destroy (Queue *Q);


