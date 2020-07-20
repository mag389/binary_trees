#include "binary_trees.h"

/**
* binary_tree_is_leaf - checks if the node is a leaf node
* Return: 1 for leaf else 0
* @node: the node to check
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!(node->left) && !(node->right))
		return (1);
	return (0);
}
