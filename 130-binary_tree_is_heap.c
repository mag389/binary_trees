#include "binary_trees.h"
size_t min_height(const binary_tree_t *tree);
/**
* binary_tree_is_heap - deterines if the tree is a heap
* Return: 1 if it is a valid max binary heap, else 0
* @tree: pointer to the root node of the tree to check
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->right) && !(tree->left))
		return (1);
	if (!(tree->left) && tree->right)
		return (0);
	if (binary_tree_height(tree->left) < binary_tree_height(tree->right))
		return (0);
	if (binary_tree_size(tree->left) < binary_tree_size(tree->right))
		return (0);
	if (min_height(tree->left) < binary_tree_height(tree->right))
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
/**
* min_height - finds the height of the binary tree
* Return: the height as a size_t
* @tree: the root node
*/
size_t min_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_left < h_right)
		return (1 + h_left);
	return (1 + h_right);
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
		return (1);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_left > h_right)
		return (1 + h_left);
	return (1 + h_right);
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
