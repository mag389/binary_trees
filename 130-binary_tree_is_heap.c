#include "binary_trees.h"
int completeness(const binary_tree_t *tree, int index, int nodes);
/**
* binary_tree_is_heap - deterines if the tree is a heap
* Return: 1 if it is a valid max binary heap, else 0
* @tree: pointer to the root node of the tree to check
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nodes, index = 0;

	if (!tree)
		return (0);

	nodes = binary_tree_size(tree);
	if (completeness(tree, index, nodes) == 0)
		return (0);	
	if (!(tree->left) && !(tree->right))
		return (1);
	if (tree->right == NULL)
		return (tree->n > tree->left->n);
	else
	{
		if (tree->n < tree->left->n)
			return (0);
		if (tree->n < tree->right->n)
			return (0);
		return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
	}
}
/**
* binary_tree_is_complete - tests completeness
* Return: 1 for complete else 0
* @tree: the root node of the tree
*/
int completeness(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (completeness(tree->left, 2 * index + 1, nodes) &&
		completeness(tree->right, 2 * index + 2, nodes));
}
/**
* binary_tree_size - returns size of the binary tree
* Return: size_t size of the tree
* @tree: pointer to root node of the tree to be measured
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
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
