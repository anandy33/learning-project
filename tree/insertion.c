#include "insertion.h"


struct node *newNode(int data)
{
	struct node *inode = (struct node*)malloc(sizeof(struct node));
	inode->data = data;
	inode->left = NULL;
	inode->right = NULL;

	return inode;
}

struct node *insert(struct node *root, int data)
{
	if(root == NULL)
		return newNode(data);
	
	if(root->data > data)
		root->left = insert(root->left, data);
	
	else if(root->data < data)
		root->right = insert(root->right, data);
	
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int main()
{
	atexit(report_mem_leak);
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 40);
	insert(root, 70);
	insert(root, 20);
	insert(root, 21);
	
	printf("recursive inorder traversal\n");
	inorder(root);
	
	printf("\nnon recursive inorder traversal\n");
	inorder_non_recursive(root);

	printf("\nnon-recursive preorder traversal\n");
	preorder_non_recursive(root);

	printf("\ndiagonal tree traversal\n");
	iterative_diagonal_traversal(root);

	printf("\n");

    return 0;
}
