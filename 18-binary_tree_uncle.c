#include "binary_trees.h"

/**
* binary_tree_uncle - returns the uncle node
* Return: the uncle binary_tree_t node
* @node: the ode to get the uncle of
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!(node->parent))
		return (NULL);
	/* basic checks, now get sibling of parent */
	if (!(node->parent->parent))
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
