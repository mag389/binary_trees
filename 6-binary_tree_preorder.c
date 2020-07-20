#include "binary_trees.h"

/**
* binary_tree_preorder - preorder traverses a binary tree
* Return: void
* @tree: pointer to root node
* @func: pointer to a function to call for each node
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
