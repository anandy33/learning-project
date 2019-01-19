#ifndef FUNCTIONS_H_INCLUDE
#define FUNCTIONS_H_INCLUDE

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void inorder_non_recursive(struct node *);

#endif

