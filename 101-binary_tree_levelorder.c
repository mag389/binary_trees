#include "binary_trees.h"

/**
* binary_tree_levelorder - traverses binary tree by level
* Return: void
* @tree: the root node of the tree
* @func: the functoin to do to the nodes
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t max_height, i;

	if (!tree || !func)
		return;
	max_height = binary_tree_height(tree);
	for (i = 0; i <= max_height; i++)
	{
		func_level(tree, func, i);
	}
}
/**
* func_level - performs function on ninary tree level
* Return: void
* @tree: root node
* @func: functoin to perform
* @level: what tree level
*/
void func_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (!tree || !func)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		func_level(tree->left, func, level - 1);
		func_level(tree->right, func, level - 1);
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
