#include "binary_trees.h"

/**
* bst_search - searches ths bst
* Return: return pointer to node with valu
* @tree: pointer to root node
* @value: value to search for
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
