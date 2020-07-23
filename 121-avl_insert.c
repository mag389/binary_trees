#include "binary_trees.h"

/**
* avl_insert - inserts new avl node
* Return: created node
* @tree: the tree to add to
* @value: new number to add
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newt, *temp, *ncheck;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	ncheck = (*tree)->parent;
	if ((*tree)->n == value)
		return (NULL);
	if ((*tree)->n > value)
	{
		if (!((*tree)->left))
		{
			(*tree)->left = binary_tree_node(*tree, value);
			newt = (*tree)->left;
			temp = rebalance((*tree)->left);
			return (newt);
		}
		else
		{
			temp = avl_insert((&(*tree)->left), value);
			while (*tree && (*tree)->parent != NULL && !ncheck)
				*tree = (*tree)->parent;
			return (temp);
		}
	}
	if ((*tree)->right == NULL)
	{
		(*tree)->right = binary_tree_node(*tree, value);
		newt = (*tree)->right;
		temp = rebalance((*tree)->right);
		return (newt);
	}
	temp = avl_insert((&(*tree)->right), value);
	while (*tree && (*tree)->parent != NULL && !ncheck)
		*tree = (*tree)->parent;
	return (temp);
}

/**
* rebalance - rebalnces the avl tree from new node up
* Return: the inserted(given arg) node
* @newt: the newly inserted node
*/
avl_t *rebalance(avl_t *newt)
{
	int balance;
	avl_t *temp;

	if (!newt || !(newt->parent) || !(newt->parent->parent))
		return (NULL);
/*	printf("--------------------------------------------\n");*/
/*	binary_tree_print(newt->parent->parent);*/
	balance = binary_tree_balance(newt->parent->parent);
	if (balance <= 1 && balance >= -1)
		return (rebalance(newt->parent));
	if (balance > 1)
	{
		if (newt->n > newt->parent->n)
		{
			newt->parent->parent->left = binary_tree_rotate_left(newt->parent);
			temp = binary_tree_rotate_right(newt->parent);
			return (temp);
		}
		temp = binary_tree_rotate_right(newt->parent->parent);
		return (temp);
	}
	else
	{
		if (newt->n < newt->parent->n)
		{
			binary_tree_rotate_right(newt->parent);
			temp = binary_tree_rotate_left(newt->parent);
			return (temp);
		}
		temp = binary_tree_rotate_left(newt->parent->parent);
		return (temp);
	}
}
