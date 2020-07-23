#include "binary_trees.h"

/**
* binary_tree_rotate_left - rotates the binary tree
* Return: the new top node
* @tree: the tree to rotate
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);
	temp = tree->right;
	if (!(tree->right))
		return (tree);
/*	NULL check*/
	tree->right = temp->left;
	if (tree->right)
		tree->right->parent = tree;
/*	dael with tree right the switching child*/
	temp->parent = tree->parent;
	tree->parent = temp;
/*	switch parents */
	if (temp->parent)
	{
		if (temp->parent->right == tree)
			temp->parent->right = temp;
		else
			temp->parent->left = temp;
	}
/*	change parent to point to new spot*/
	temp->left = tree;
	return (temp);
}
