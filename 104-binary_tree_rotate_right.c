#include "binary_trees.h"

/**
* binary_tree_rotate_right - rotates the binary tree
* Return: the new top node
* @tree: the tree to rotate
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	temp = tree->left;
	if (tree->left)
		tree->left = temp->right;
	if (tree->left)
		tree->left->parent = tree;
	temp->parent = tree->parent;
	tree->parent = temp;
	temp->right = tree;
	return (temp);
}
