#include "binary_trees.h"

/**
* binary_tree_is_complete - tests completeness
* Return: 1 for complete else 0
* @tree: the root node of the tree
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t max_height, i;
	int hitleaf = 0;

	if (!tree)
		return (0);
	max_height = binary_tree_height(tree);
	for (i = 0; i <= max_height; i++)
	{
		comp_check(tree, &hitleaf, i);
		if (hitleaf == 2)
			return (0);
	}
/*	printf("hitleaf is %i\n", hitleaf);*/
	return (1);
}
/**
* comp_check - checks if the current node can be in a complete tree
* Return: void
* @tree: root node
* @hitleaf: has a leaf been hit
* @level: what tree level
*/
void comp_check(const binary_tree_t *tree, int *hitleaf, size_t level)
{
	if (!tree)
	{
		if (*hitleaf == 0)
			*hitleaf = 1;
		return;
	}
	if (level == 0)
	{
/*	printf("%i:%i:%i\n",*hitleaf, tree->n, (int) level);*/
		if (*hitleaf == 1)
		{
			*hitleaf = 2;
		}
	}
	else
	{
		comp_check(tree->left, hitleaf, level - 1);
		comp_check(tree->right, hitleaf, level - 1);
	}
}
/**
* binary_tree_height - finds the height of the binary tree
* Return: the height as a size_t
* @tree: the root node
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (0);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_left > h_right)
		return (1 + h_left);
	return (1 + h_right);
}
