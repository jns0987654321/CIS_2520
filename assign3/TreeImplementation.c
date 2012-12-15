
#include "TreeInterface.h"
/* some code here (e.g., #include directives, static functions) */


void Initialize (Tree *T,
				 void * (*copyItem) (void *, void *),
				 void (*destroyItem) (void *),
				 int (*compareItems) (void *, void *)) {
	/* some code here */
}


void Insert (Tree *T, void *I) {
	/* some code here */
}


int Minimum (Tree *T, void *I) {
	return 1; /* change this */
}


int Successor (Tree *T, void *I) {
	return 1; /* change that */
}


void Destroy (Tree *T) {
	/* some code here */
}

