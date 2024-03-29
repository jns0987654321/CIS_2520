/*********************************************************************
 * FILE NAME: TreeInterface.h
 * PURPOSE: Interface of a generic Binary Search Tree ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 4)
 * DATE: 25/11/2011
 *********************************************************************/
#include "TreeType.h"

/*********************************************************************
 * FUNCTION NAME: Initialize
 * PURPOSE: Sets a Tree variable to the empty Binary Search Tree.
 * ARGUMENTS: . The address of the Tree variable to be initialized
 *              (Tree *) 
 *            . A pointer to a copy function
 *              ---------------------------- 
 *              PURPOSE: Makes a copy of an item.
 *              ARGUMENTS: . NULL, or the address (void *) of  
 *                           the location in memory where the 
 *                           copy must be stored
 *                         . The address (void *) of the item 
 *                           to be copied
 *              RETURNS: The address (void *) of the location in
 *                       memory where the copy has been stored
 *              NOTES: If the first argument is NULL, the copy
 *                     function allocates memory for the copy,
 *                     and this memory should later be freed
 *                     by the destroy function below.
 *              -------------------------------
 *            . A pointer to a destroy function
 *              -------------------------------
 *              PURPOSE: Frees memory that may have been 
 *                       allocated by the copy function above.
 *              ARGUMENT: The address of the item to be destroyed
 *                        (void *); this address must have been
 *                        returned by the copy function called
 *                        with NULL as its first argument
 *              -------------------------------
 *            . A pointer to a compare function
 *              -------------------------------
 *              PURPOSE: Compares two items.
 *              ARGUMENTS: . A pointer to a first item (void *)
 *                         . A pointer to a second item (void *)
 *              RETURNS: The integer
 *                       -1 if the 1st item is less than the 2nd item,
 *                        0 if the two items are equal,
 *                        1 otherwise
 *              -----------------------
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Tree variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void Initialize (Tree *T,
						void * (*copyItem) (void *, void *),
						void (*destroyItem) (void *),
						int (*compareItems) (void *, void *));

/*********************************************************************
 * FUNCTION NAME: Insert
 * PURPOSE: Inserts an item in a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address of the item to be inserted (void *)
 *********************************************************************/
extern void Insert (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: Minimum
 * PURPOSE: Finds the least item (according to the compare 
 *          function whose address was passed to Initialize)
 *          of a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy 
 *              of the least item should be stored 
 * RETURNS: 1 if the minimum has been found,
 *          i.e., if the Tree is not empty,
 *          0 otherwise
 *********************************************************************/
extern int Minimum (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: Successor
 * PURPOSE: Finds the successor (according to the compare 
 *          function whose address was passed to Initialize)
 *          in a Binary Search Tree of the last item found by
 *          Successor or Minimum (whichever was called last).
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy 
 *              of the successor should be stored 
 * RETURNS: 1 if the successor has been found,
 *          i.e., if the Tree is not empty and if the
 *          last item found by Minimum or Successor
 *          was not the greatest element of the Tree,
 *          0 otherwise
 * NOTES: A call to Successor must be immediately
 *        preceded by a call to Successor or Minimum.
 *********************************************************************/
extern int Successor (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: Size
 * PURPOSE: Finds the number of items stored in a Binary Search Tree.
 * ARGUMENT: The address of the Tree (Tree *) 
 * RETURNS: The number of items stored in the Tree
 *********************************************************************/
extern int Size (Tree *T);

/*********************************************************************
 * FUNCTION NAME: Height
 * PURPOSE: Calculates the height of a Binary Search Tree.
 * ARGUMENT: The address of the Tree (Tree *) 
 * RETURNS: The height of the Tree
 * NOTES: The height of the empty Tree is -1.
 *********************************************************************/
extern int Height (Tree *T);

/*********************************************************************
 * FUNCTION NAME: Balanced
 * PURPOSE: Checks whether a Binary Search Tree is balanced.
 * ARGUMENT: The address of the Tree (Tree *) 
 * RETURNS: 1 if the Tree is balanced, 0 otherwise
 * NOTES: A Tree is balanced if it is empty or if for any node N
 *        the heights of N's subTrees are equal or differ by 1.
 *********************************************************************/
extern int Balanced (Tree *T);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been 
 *          allocated by Initialize and Insert.
 * ARGUMENTS: The address of the Tree to be destroyed (Tree *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void Destroy (Tree *T);


