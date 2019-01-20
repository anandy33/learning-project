#include "insertion.h"

struct sNode
{
	struct node *inode;
	struct sNode *next;
};

static void push(struct sNode **st, struct node *inode)
{
	struct sNode *newNode = (struct sNode *)malloc(sizeof(struct sNode));

	if(newNode == NULL)
	{
		printf("Stack Overflow!!!\n");
		getchar();
		exit(0);
	}

	newNode->inode = inode;
	newNode->next = (*st);
	(*st) = newNode;
}

static int isEmpty(struct sNode *st)
{
	if(st == NULL)
		return 1;
	return 0;
}

static struct node *pop(struct sNode **st)
{
	struct sNode *Top = (*st);
	struct node *inode = Top->inode;
	(*st) = Top->next;

	free(Top);
	return inode;
}

void inorder_non_recursive(struct node *root)
{
	struct node *current = root;
	struct sNode *st = NULL;
	int done = 1;

	while(done)
	{
		if(current)
		{
			push(&st, current);
			current = current->left;
		}
		else
		{
			if(!isEmpty(st))
			{
				current = pop(&st);
				printf("%d ", current->data);
				current = current->right;
			}
			else
				done = 0;
		}
	}
}
