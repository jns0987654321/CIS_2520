/*********************************************************************
 * FILE NAME: HeapImplementation.c
 * PURPOSE: Implementation of a generic Heap ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 4)
 * DATE: 25/11/2011
 *********************************************************************/


#include "HeapInterface.h"
#include <stdlib.h>
#include <string.h>


int Initialize (Heap *H,
				int capacity,
				void * (*copyItem) (void *, void *),
				void (*destroyItem) (void *),
				int (*compareItems) (void *, void *)) {
	H->heap=malloc(sizeof(void *)*(capacity+1));
	if(H->heap==NULL) return 0;
	H->capacity=capacity;
	H->numberOfItems=0;
	H->copyItem=copyItem;
	H->destroyItem=destroyItem;
	H->compareItems=compareItems;
	return 1;
}


int Insert (Heap *H, void *I) {
	int parent, child;
	void *temp;

	temp=H->copyItem(NULL,I);
	if(temp==NULL) return 0;
	H->numberOfItems++;
	H->heap[H->numberOfItems]=temp;
	
	child=H->numberOfItems;
	parent=child/2;
	while(child!=1 && H->compareItems(H->heap[child],H->heap[parent])>0) {
		temp=H->heap[parent];
		H->heap[parent]=H->heap[child];
		H->heap[child]=temp;
		child=parent;
		parent=child/2;
	}
	return 1;
}


void Remove (Heap *H) {
	int parent, child;
	void *temp;
	
	H->destroyItem(H->heap[1]);
	H->heap[1]=H->heap[H->numberOfItems];
	H->numberOfItems--;
	
	parent=1;
	child=2; 
	if(child<H->numberOfItems && H->compareItems(H->heap[child],H->heap[child+1])<0)
		child++;
	while(child<=H->numberOfItems && H->compareItems(H->heap[child],H->heap[parent])>0) {
		temp=H->heap[parent];
		H->heap[parent]=H->heap[child];
		H->heap[child]=temp;
		parent=child;
		child=parent*2;
		if(child<H->numberOfItems && H->compareItems(H->heap[child],H->heap[child+1])<0)
			child++;		
	}
}


void Top (Heap *H, void *I) {
	H->copyItem(I,H->heap[1]);
}


int Full (Heap *H) {
	return H->numberOfItems==H->capacity;
}


int Empty (Heap *H) {
	return H->numberOfItems==0;
}


void Destroy (Heap *H) {
	int i;
	for(i=1;i<=H->numberOfItems;i++)	
		H->destroyItem(H->heap[i]);
	free(H->heap);
}
