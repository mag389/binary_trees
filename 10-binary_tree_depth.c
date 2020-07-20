#include "binary_trees.h"

/**
* binary_tree_depth - retruns depth of the binary tree at a node
* Return: size_t depth
* @tree: the node to test
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->parent))
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
