#include "binary_trees.h"
int completeness(const binary_tree_t *tree, int index, int nodes);
heap_t *last_levelorder(heap_t *root, int index, int size);
heap_t *rebuild(heap_t *root);
/**
* heap_extract - extracts the top value from the heap
* Return: the value if extracted else 0
* @root: double pointer to root node
*/
int heap_extract(heap_t **root)
{
	/*int ret, sizeleft, sizeright, lf, rf, temp, size;*/
	int temp, size;
	heap_t *last;

	if (!root || !(*root))
		return (0);
	size = binary_tree_size(*root);
	last = last_levelorder(*root, 0, size - 1);
/*
*	if (last)
*		printf("the last exists and is %i\n", last->n);
*	else
*		printf("------------------------------\n");
*/
	temp = last->n;
	last->n = (*root)->n;
	(*root)->n = temp;
	if (last->parent && last->parent->left == last)
		last->parent->left = NULL;
	if (last->parent && last->parent->right == last)
		last->parent->right = NULL;
	temp = last->n;
	free(last);
	rebuild(*root);
	return (temp);
/*
*	if ((!(*root)->left) && !((*root)->right))
*	{
*		ret = (*root)->n;
*		if ((*root)->parent->left == (*root))
*			(*root)->parent->left = NULL;
*		else
*			(*root)->parent->right = NULL;
*		free(*root);
*		return (ret);
*	}
*/
	/* else return the recursive call on the child after swiching values*/
/*
*	sizeleft = binary_tree_size((*root)->left);
*	sizeright = binary_tree_size((*root)->right);
*	lf = binary_tree_is_full((*root)->left);
*	rf = binary_tree_is_full((*root)->right);
*	printf("sizel: %i  - sizer: %i - lf: %i - rf %i\n",
*	 sizeleft, sizeright, lf, rf);
*	if (sizeleft == sizeright || (sizeleft != sizeright && lf == 1 && rf == 1))
*	{
*/
/*		binary_tree_print(*root);*/
/*
*		temp = (*root)->n;
*		(*root)->n = (*root)->right->n;
*		(*root)->right->n = temp;
*		printf("____________\n");
*		return (heap_extract( &((*root)->right) ));
*	}
*	else
*	{
*		temp = (*root)->n;
*		(*root)->n = (*root)->left->n;
*		(*root)->left->n = temp;
*		return (heap_extract(&((*root)->left)));
*	}
*/
}
/**
* last_levelorder - return last node in level order
* Return: heap_t
* @root: the root to get the last level order of
* @index: the current index of root
* @size: the total size of the tree
*/
heap_t *last_levelorder(heap_t *root, int index, int size)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);
/*	printf("in the last level %i, %i\n", index, size);*/
	if (index > size)
		return (NULL);
	if (index == size)
		return (root);
	left = last_levelorder(root->left, 2 * index + 1, size);
	right = last_levelorder(root->right, 2 * index + 2, size);
	if (left)
		return (left);
	if (right)
		return (right);
	return (NULL);
}
/**
* rebuild - fixes the heap
* Return: the former head node
* @root: the root
*/
heap_t *rebuild(heap_t *root)
{
	int temp;

	if (!root)
		return (NULL);
	if (!(root->left) && !(root->right))
		return (NULL);
	if (root->left && !(root->right))
	{
		if (root->left->n > root->n)
		{
			temp = root->left->n;
			root->left->n = root->n;
			root->n = temp;
			rebuild(root->left);
		}
	}
	else if (root->right && !(root->left))
	{
		if (root->right->n > root->n)
		{
			temp = root->right->n;
			root->right->n = root->n;
			root->n = temp;
			rebuild(root->right);
		}
	}
	else if (root->left->n > root->n && root->left->n > root->right->n)
	{
		temp = root->left->n;
		root->left->n = root->n;
		root->n = temp;
		rebuild(root->left);
	}
	else if (root->right->n > root->n && root->right->n > root->left->n)
	{
		temp = root->right->n;
		root->right->n = root->n;
		root->n = temp;
		rebuild(root->right);
	}
	return (NULL);
}
