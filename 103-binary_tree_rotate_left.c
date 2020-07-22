#include "binary_trees.h"

/**
* binary_tree_rotate_left - rotates the binary tree
* Return: the new top node
* @tree: the tree to rotate
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	temp = tree->right;
	if (!(tree->right))
		return (tree);
	tree->right = temp->left;
	if (tree->right)
		tree->right->parent = tree;
	temp->parent = tree->parent;
	if (temp->parent)
	{
		if (temp->parent->right == tree)
			temp->parent->right = tree;
		else
			temp->parent->left = tree;
	}
	tree->parent = temp;
	temp->left = tree;
	return (temp);
}
