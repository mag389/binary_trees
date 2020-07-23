#include "binary_trees.h"

/**
* binary_tree_rotate_right - rotates the binary tree
* Return: the new top node
* @tree: the tree to rotate
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	temp = tree->left;
	if (tree->left)
		tree->left = temp->right;
	if (tree->left)
		tree->left->parent = tree;
	temp->parent = tree->parent;
	tree->parent = temp;
	if (temp->parent)
	{
		if (temp->parent->right == tree)
			temp->parent->right = temp;
		else
			temp->parent->left = temp;
	}
	temp->right = tree;
	return (temp);
}
