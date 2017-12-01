#include <stdio.h>
#include <stdlib.h>

typedef struct BTree {
	int value;
	struct BTree *left, *right;
} BTree;

BTree *insert(BTree *root, int value) {
	if (root == NULL) {
		BTree *new_node = (BTree*)malloc(sizeof(BTree));
		new_node->value = value;
		new_node->left = new_node->right = NULL;
		return new_node;
	}
	if (value < root->value) {        /* insert left */
		root->left = insert(root->left, value);
	}
	else if (value > root->value) {   /* insert right */
		root->right = insert(root->right, value);
	}
	else {
		/* already in the tree */
	}
	return root;
}

void printTree(BTree * this)
{
	if (this)
	{
		printTree(this->left);
		printf("%d ", this->value);
		printTree(this->right);
	}
}

void destroyTree(BTree * this)
{
	if (this)
	{
		destroyTree(this->left);
		destroyTree(this->right);
		free(this);
	}
}

inline size_t getNumberOfNode(BTree * this)
{
	return this ? getNumberOfNode(this->left) + getNumberOfNode(this->right) + 1 : 0;
}

inline int getSumOfValue(BTree * this)
{
	return this ? getSumOfValue(this->left) + getSumOfValue(this->right) + this->value : 0;
}

int main(void) {
	int sample[] = { 15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0 };
	BTree *root = NULL;
	int i;
	for (i = 0; sample[i] > 0; i++)
		root = insert(root, sample[i]);

	/* Call your functions here! */
	printTree(root);
	printf("\nNumber of node is : %u\n", getNumberOfNode(root));
	printf("Sum of value is : %d\n", getSumOfValue(root));
	destroyTree(root);

#ifdef WIN32
	system("pause");
#endif

	return 0;
}