#include "binary_trees.h"
/**
* binary_tree_is_perfect - checks perfection
* Return: 1 for perfect, else 0
* @tree: the root node to check
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_p, right_p;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);
	left_p = binary_tree_is_perfect(tree->left);
	right_p = binary_tree_is_perfect(tree->right);
	return (left_p && right_p);
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
