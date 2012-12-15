
typedef struct TreeNodeTag {
	void *item;
	struct TreeNodeTag *left, *right, *parent;
} TreeNode;

typedef struct {
	TreeNode *root;
	TreeNode *current;
	void * (*copyItem) (void *, void *);
	void (*destroyItem) (void *);
	int (*compareItems) (void *, void *);
	int size;
} Tree;



