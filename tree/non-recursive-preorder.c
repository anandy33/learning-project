#include "insertion.h"

struct sNode
{
	struct node *inode;
	struct sNode *next;
};

static void push(struct sNode **top, struct node *inode)
{
	struct sNode *st = (struct sNode *)malloc(sizeof(struct sNode));

	st->inode = inode;
	st->next = (*top);
	(*top) = st;
}

static struct node *pop(struct sNode **top)
{
	struct sNode *temp = (*top);
	struct node *inode = temp->inode;
	(*top) = temp->next;
	free(temp);
	return inode;
}

static bool isEmpty(struct sNode *st)
{
	if(st == NULL)
		return true;
	return false;
}

void preorder_non_recursive(struct node *root)
{
	struct node *current = root;
	struct sNode *st = NULL;
	push(&st, current);

	while(!isEmpty(st))
	{
		current = pop(&st);
		printf("%d ", current->data);

		if(current->right)
			push(&st, current->right);

		if(current->left)
			push(&st, current->left);
	}
}
