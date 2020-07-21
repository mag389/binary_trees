#include "binary_trees.h"

/**
* binary_trees_ancestor - find lowest common ancestor
* Return: pointer to the ancestor binary_tree_t
* @first: pointer to first node
* @second: pointer to second
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t d_first, d_second;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	d_first = binary_tree_depth(first);
	d_second = binary_tree_depth(second);
	if (d_first < d_second)
		return (binary_trees_ancestor(first, second->parent));
	if (d_first > d_second)
		return (binary_trees_ancestor(first->parent, second));
	return (binary_trees_ancestor(first->parent, second->parent));
}

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
