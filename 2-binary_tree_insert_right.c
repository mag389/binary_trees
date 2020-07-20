#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts new node in right place
* Return: returns new node or NULL
* @parent: the parent node of the new node
* @value: the value in the new node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right;

	if (parent == NULL)
		return (NULL);
	new_right = binary_tree_node(parent, value);
	if (!new_right)
		return (NULL);
	if (!(parent->right))
	{
		parent->right = new_right;
		return (new_right);
	}
	(parent->right)->parent = new_right;
	new_right->right = parent->right;
	parent->right = new_right;
	return (new_right);
}
