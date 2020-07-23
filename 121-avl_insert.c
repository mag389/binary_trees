#include "binary_trees.h"

/**
* avl_insert - inserts new avl node
* Return: created node
* @tree: the tree to add to
* @value: new number to add
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newt;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if ((*tree)->n > value)
	{
		if (!((*tree)->left))
		{
			(*tree)->left = binary_tree_node(*tree, value);
			newt = (*tree)->left;
			rebalance((*tree)->left);
			return (newt);
		}
		else
			return (avl_insert((&(*tree)->left), value));
	}
	else if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			newt = (*tree)->right;
			rebalance((*tree)->right);
			return (newt);
		}
		else
			return (avl_insert((&(*tree)->right), value));
	}
	return (NULL);
}

/**
* rebalance - rebalnces the avl tree from new node up
* Return: the inserted(given arg) node
* @newt: the newly inserted node
*/
avl_t *rebalance(avl_t *newt)
{
	int balance;

	if (!newt || !(newt->parent) || !(newt->parent->parent))
		return (NULL);
/*	binary_tree_print(newt);*/
/*	binary_tree_print(newt->parent->parent);*/
	balance = binary_tree_balance(newt->parent->parent);
/*	printf("balance of node %i is %i\n", newt->n, balance);*/
	if (balance <= 1 && balance >= -1)
		return (rebalance(newt->parent));
	/*else rebalance at grandparent */
	if (balance > 1)
	{
		printf("first if correct\n");
		if (newt->n > newt->parent->n)
		{
/*
*			printf("1: rotate around %i %i\n",
*			 newt->parent->n, newt->parent->parent->n);
*		printf("%i %i %i %i %i \n", newt->n, newt->parent->n,
*			newt->parent->parent->n,
*			newt->parent->parent->left->n,
*			newt->parent->parent->left->right->n);
*/
			newt->parent->parent->left = binary_tree_rotate_left(newt->parent);
/*
*		printf("%i %i %i %i %i \n", newt->n, newt->parent->n, newt->parent->parent->n,
*                       newt->parent->parent->left->n, newt->parent->parent->right->left->n);
*/
			binary_tree_print(newt->parent);
			binary_tree_rotate_right(newt->parent);
			return (NULL);
		}
		binary_tree_rotate_right(newt->parent->parent);
		return (NULL);
	}
	else
	{
		if (newt->n < newt->parent->n)
		{
/*			printf("2: rotate around %i %i\n", newt->parent->n, newt->parent->parent->n);*/
			binary_tree_rotate_right(newt->parent);
			binary_tree_rotate_left(newt->parent);
			return (NULL);
		}
		binary_tree_rotate_left(newt->parent->parent);
		return (NULL);
	}
}
