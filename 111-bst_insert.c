#include "binary_trees.h"

/**
* bst_insert - inserts new node to bst
* Return: the new node
* @tree: the tree to insert into, double pointer
* @value: the value of the new node
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
/*	printf("tree n=%i\n", (*tree)->n);*/
	if ((*tree)->n > value)
	{
/*		printf("in the left if\n");*/
		if (!((*tree)->left))
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (bst_insert((&(*tree)->left), value));
		}
	}
	else if ((*tree)->n < value)
	{
/*		printf("in the right if\n");*/
		if ((*tree)->right == NULL)
		{
/*			printf("in the if in if\n");*/
			(*tree)->right = binary_tree_node(*tree, value);
/*			printf("in the ifnif passed assignemnt\n");*/
			return ((*tree)->right);
		}
		else
		{
			return (bst_insert(&((*tree)->right), value));
		}
	}
	return (NULL);
}
