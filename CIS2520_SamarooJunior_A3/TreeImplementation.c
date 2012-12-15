/*
 *For Full description of these functions please
 *see TreeInterface.h
 *
 *Functions psuedocode taken from textbook:
 *Introduction to Algorithms and class notes.
 */

#include "TreeInterface.h"
#include <stdio.h>
#include <stdlib.h>

void destroyNode(TreeNode *); //Used by the Destroy function.

/* Initilizes the binary tree. This function is called once. */
void Initialize (Tree *T,
				 void * (*copyItem) (void *, void *),
				 void (*destroyItem) (void *),
				 int (*compareItems) (void *, void *)) 
{
    T->root = NULL;
    T->current = NULL;
    T->copyItem = copyItem;
    T->compareItems = compareItems;
    T->destroyItem = destroyItem;
}

/* Inserts the item I into the binary tree T. */
void Insert (Tree *T, void *I) 
{
    TreeNode *X, *Y, *toInsert;
    toInsert = malloc(sizeof(TreeNode));   // allocates memory for node to be inserted
    toInsert->item = T->copyItem(NULL, I);
    toInsert->parent= NULL;
    toInsert->left= NULL;
    toInsert->right= NULL;
    
    Y = NULL;       // Tempoary
    X = T->root;    // nodes
    
    /* Loop transverses tree to find position to be inserted */
    while (X) 
    {
        Y = X;
        if ((T->compareItems(toInsert->item, X->item)) == -1) 
        {
            X = X->left; // X grade < Y grade
        }else{
            X = X->right; // X grade > Y grade
        }
    }
    toInsert->parent = Y;
    
    if (Y == NULL) 
    {
        T->root = toInsert;         // Tree is empty
    }
    else if ((T->compareItems(toInsert->item, Y->item)) == -1) {
        Y->left = toInsert; // 'toInsert' grade is < Y grade
    }else{
        Y->right = toInsert;    // 'toInsert' grade is > Y grade
    }
    T->destroyItem(toInsert->item);
}

/* Finds minimum item I in binary tree T. 
 * Return 1 if found, 0 otherwise.
 */
int Minimum (Tree *T, void *I) 
{
    TreeNode *temp;
    T->current = T->root;
    temp = T->current;
    
    /* Moves down tree to least item */
    while (temp->left) 
    {
       temp = temp->left;
    }
    if (temp == NULL) 
    {
        return 0; // tree is empty
    }else{
        T->copyItem(I , temp->item); // copies minimum item to I
        T->current = temp;
        return 1; // minimum item found
    }
}

/* Finds the successor I of last item found by Successor or Minimum. 
 * Return 1 if found, 0 otherwise.
 */
int Successor (Tree *T, void *I) 
{    
    TreeNode *temp, *Y; //transversal nodes
    temp = T->current;
    if (temp->right) 
    {
        //Move to right
        temp = temp->right;
        while (temp->left) 
        {   
            // Keep moving to left
            temp = temp->left;
        }
        T->copyItem(I , temp->item);
        T->current = temp;
        return 1; // sucessor found
    }
    Y = T->current;
    
    while ((T->current->parent)) 
    {
        // Loop moves up parents until parent is null
        temp = T->current;
        T->current = T->current->parent;
        if (temp != T->current->right) // new right node
        {
            T->copyItem(I, T->current->item);
            return 1; // sucessor found
        }
    }
    
    T->copyItem(I, T->current->item);
    if ((T->current->parent == NULL) && (T->current->right == temp)) 
    {
        return 0; // End of tree reached, no successors
    }else
        return 1; // sucessor found
}

/* Destroys a binary tree T. */
void Destroy (Tree *T) 
{
    //Calls recursive function to destroy nodes
    destroyNode(T->root);
}

/* Recursive function that destroys tree nodes. */
void destroyNode(TreeNode *studentNode) 
{    
    if (studentNode) 
    {
        if (studentNode->left)
            destroyNode(studentNode->left);     //move left
        if (studentNode->right)
            destroyNode(studentNode->right);    // move right
        free(studentNode);  //deallocates memory
        studentNode = NULL;
    }
}
