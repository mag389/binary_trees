#include "binary_trees.h"

/**
* binary_tree_sibling - finds the sibling of the node
* Return: the sibling
* @node: pointer to node to get sibling of
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	if (!(node->parent))
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
