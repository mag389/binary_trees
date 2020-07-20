#include "binary_trees.h"

/**
* binary_tree_insert_left - inserts new node in left place
* Return: returns new node or NULL
* @parent: the parent node of the new node
* @value: the value in the new node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;

	if (parent == NULL)
		return (NULL);
	new_left = binary_tree_node(parent, value);
	if (!new_left)
		return (NULL);
	if (!(parent->left))
	{
		parent->left = new_left;
		return (new_left);
	}
	(parent->left)->parent = new_left;
	new_left->left = parent->left;
	parent->left = new_left;
	return (new_left);
}
