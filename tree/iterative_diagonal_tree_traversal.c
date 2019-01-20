#include "insertion.h"

struct Qnode
{
	struct node *inode;
	struct Qnode *next;
};

struct Queue
{
	struct Qnode *front;
	struct Qnode *rear;
};

static struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->rear = NULL;

	return q;
}

static struct Qnode *newNode(struct node *inode)
{
	struct Qnode *temp = (struct Qnode *)malloc(sizeof(struct Qnode));
	temp->inode = inode;
	temp->next = NULL;

	return temp;
}

static void enqueue(struct Queue *que, struct node *inode)
{
	struct Qnode *temp = newNode(inode);

	if(que->rear == NULL)
	{
		que->front = que->rear = temp;
		return;
	}
	
	que->rear->next = temp;
	que->rear = temp;
}

static bool isEmpty(struct Queue *q)
{
	if(q->front == NULL)
		return true;
	return false;
}

static struct Qnode *dequeue(struct Queue *que)
{
	if(que->front == NULL)
		return NULL;

	struct Qnode *temp = que->front;
	que->front = temp->next;

	if(que->front == NULL)
		que->front = que->rear = NULL;
	
	return temp;
}

void iterative_diagonal_traversal(struct node *root)
{
	if(root == NULL)
		return;
	struct node *current = root;
	
	struct Queue *que = createQueue();
	enqueue(que, current);
	enqueue(que, NULL);

	while(!isEmpty(que))
	{
		struct Qnode *node = dequeue(que);
		if(!node)
			return;
		struct node *temp = node->inode;

		if(temp == NULL)
		{
			if(isEmpty(que))
				return;
			printf("\n");
			enqueue(que, NULL);
		}
		else
		{
			while(temp)
			{
				printf("%d ", temp->data);
				
				if(temp->left)
					enqueue(que, temp->left);

				temp = temp->right;
			}
		}

	}

}



