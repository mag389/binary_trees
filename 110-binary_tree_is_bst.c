#include "binary_trees.h"

/**
* binary_tree_is_bst - determines if the tree is a bst
* Return: 1 if valid bst else 0
* @tree: the root node to check
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
	{
/*		printf("%i is\n", tree->n);*/
		return (1);
	}
/*	printf("right before the if\n");*/
	if (isleft(tree->left, tree->n) && isright(tree->right, tree->n))
	{
/*		printf("in the big if\n");*/
		if (tree->left)
			left = binary_tree_is_bst(tree->left);
		if (tree->right)
			right = binary_tree_is_bst(tree->right);
		return (left && right);
	}
/*	printf("%i is not\n", tree->n);*/
	return (0);
}
/**
* isleft - tests if the left side is < the root
* Return: 1 for valid else 0
* @tree: the tree to check comparison for
* @num: the number to compare against
*/
int isleft(const binary_tree_t *tree, int num)
{
	if (!tree)
		return (1);
/*	printf("comparing %i < %i\n", tree->n, num);*/
	if (tree->n >= num)
		return (0);
/*
*	if (tree->left)
*		printf("left: %i\n", tree->left->n);
*	if (tree->right)
*		printf("right: %i\n", tree->right->n);
*/
	return (isleft(tree->left, num) && isleft(tree->right, num));
}
/**
* isright - tests if the left side is < the root
* Return: 1 for valid else 0
* @tree: the tree to check comparison for
* @num: the number to compare against
*/
int isright(const binary_tree_t *tree, int num)
{
	if (!tree)
		return (1);
	if (tree->n <= num)
		return (0);
	return (isright(tree->left, num) && isright(tree->right, num));
}
