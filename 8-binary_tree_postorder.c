#include "binary_trees.h"

/**
* binary_tree_postorder - postorder traverses a binary tree
* Return: void
* @tree: pointer to root node
* @func: pointer to a function to call for each node
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
