

typedef struct {
	void **heap;
	int capacity;
	int numberOfItems;
	void * (*copyItem) (void *, void *);
	void (*destroyItem) (void *);
	int (*compareItems) (void *, void *);
} Heap;



