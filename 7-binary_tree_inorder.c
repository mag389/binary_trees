#include "binary_trees.h"

/**
* binary_tree_inorder - inorder traverses a binary tree
* Return: void
* @tree: pointer to root node
* @func: pointer to a function to call for each node
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
