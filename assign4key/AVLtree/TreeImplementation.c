/*********************************************************************
 * FILE NAME: TreeImplementation.c
 * PURPOSE: Implementation of a generic Binary Search Tree ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 4)
 * DATE: 25/11/2011
 *********************************************************************/


#include "TreeInterface.h"
#include <stdlib.h>
#include <string.h>


static TreeNode * insert (Tree *T, void *I) {
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
	return N;
}


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
	TreeNode *N, *A, *B, *C, *P;
	TreeNode *T1, *T2, *T3, *T4;
	int i;
	
	N=insert(T,I);
	if(N->parent==NULL || N->parent->parent==NULL) return;
	while(balanced(N->parent->parent)!=-2) {
		N=N->parent;
		if(N->parent->parent==NULL) return;
	}
	
	A=N; B=N->parent;
	C=B->parent; P=C->parent;
	if(P==NULL) i=0;
	else if(P->left==C) i=-1;
	else i=1;
	
	if(C->left==B) 
		if(B->left==A) {
			T2=A->right; T3=B->right; 
		}
		else {
			N=A; A=B; B=N;
			T2=B->left; T3=B->right; 
		}
	else 
		if(B->left==A) {
			N=A; A=C; C=B; B=N;
			T2=B->left; T3=B->right; 
		}
		else {
			N=A; A=C; C=N;
			T2=B->left; T3=C->left;
		}	
	
	T1=A->left; T4=C->right;
	A->right=T2; C->left=T3;
	B->left=A; B->right=C; 
	A->parent=B; C->parent=B;
	if(T1!=NULL) T1->parent=A; 
	if(T2!=NULL) T2->parent=A;
	if(T3!=NULL) T3->parent=C;
 	if(T4!=NULL) T4->parent=C;
	if(i==0) {T->root=B; B->parent=NULL;}
	else if(i==-1) {P->left=B; B->parent=P;}
	else {P->right=B; B->parent=P;}
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

