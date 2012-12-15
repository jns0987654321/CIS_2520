/*********************************************************************
 * FILE NAME: TreeImplementation.c
 * PURPOSE: Implementation of a generic Binary Search Tree ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 4)
 * DATE: 25/11/2011
 *********************************************************************/


#include "TreeInterface.h"
#include <stdlib.h>
#include <string.h>


static TreeNode * minimum (TreeNode *N) {
	while(N->left!=NULL) N=N->left;
	return N;
}


static int height (TreeNode *N) {
	int hleft, hright;
	if(N==NULL) return -1;
	hleft=height(N->left);
	hright=height(N->right);
	if(hleft<hright) return 1+hright;
	else return 1+hleft;
}


static int balanced (TreeNode *N) {
	int hleft, hright;
	if(N==NULL) return -1;
	hleft=balanced(N->left);
	if(hleft==-2) return -2;
	hright=balanced(N->right);
	if(hright==-2) return -2;
	if(hleft-hright<-1 || hleft-hright>1) return -2;
	if(hleft<hright) return 1+hright;
	else return 1+hleft;
}


static void destroy (TreeNode *N, Tree *T) {
	if(N!=NULL) {
		destroy(N->left,T);
		destroy(N->right,T);
		T->destroyItem(N->item);
		free(N);
	}
}


void Initialize (Tree *T,
				 void * (*copyItem) (void *, void *),
				 void (*destroyItem) (void *),
				 int (*compareItems) (void *, void *)) {
	T->root=NULL;
	T->copyItem=copyItem;
	T->destroyItem=destroyItem;
	T->compareItems=compareItems;
	T->size=0;
}


void Insert (Tree *T, void *I) {
	TreeNode *N, *P, *Q;
	
	N=malloc(sizeof(TreeNode));
	N->item=T->copyItem(NULL,I);
	N->right=NULL;
	N->left=NULL;
	P=T->root;
	Q=NULL;
	
	while(P!=NULL) {
		Q=P;
		if(T->compareItems(I,P->item)<0) P=P->left;
		else P=P->right;
	}
	
	N->parent=Q;
	if(Q==NULL) T->root=N;
	else if(T->compareItems(I,Q->item)<0) Q->left=N;
	else Q->right=N;
	T->size++;
}


int Minimum (Tree *T, void *I) {
	TreeNode *N;
	if(T->root==NULL) return 0;
	N=minimum(T->root);
	T->current=N;
	T->copyItem(I,N->item);
	return 1;
}


int Successor (Tree *T, void *I) {
	TreeNode *N, *P;
	if(T->root==NULL) return 0;
	if((N=T->current->right)!=NULL) {
		P=minimum(N);
		T->current=P;
		T->copyItem(I,P->item);
		return 1;
	}
	N=T->current;
	P=N->parent;
	while(P!=NULL && N==P->right) {
		N=P;
		P=P->parent;
	}
	if(P==NULL) return 0;
	T->current=P;
	T->copyItem(I,P->item);
	return 1;
}


int Size (Tree *T) {
	return T->size;
}


int Height (Tree *T) {
	return height(T->root);
}


int Balanced (Tree *T) {
	if(balanced(T->root)==-2) return 0;
	return 1;
}


void Destroy (Tree *T) {
	destroy(T->root,T);	
}

