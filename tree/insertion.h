#ifndef FUNCTIONS_H_INCLUDE
#define FUNCTIONS_H_INCLUDE

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "leak_detector_c.h"

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void inorder_non_recursive(struct node *);
void preorder_non_recursive(struct node *);
void iterative_diagonal_traversal(struct node *root);

#endif

