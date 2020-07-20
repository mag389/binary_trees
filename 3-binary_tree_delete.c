#include "binary_trees.h"

/**
* binary_tree_delete - deletes the whole tree
* Return: void
* @tree: the tree to delete
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
