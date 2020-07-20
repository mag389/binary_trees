#include "binary_trees.h"

/**
* binary_tree_is_full - checks if the binary tree is full
* Return: 1 for full else 0
* @tree: pointer to root node to check
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->right) && !(tree->left))
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
