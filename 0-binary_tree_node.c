#include "binary_trees.h"

/**
* binary_tree_node - creates new node
* Return: the new node or NULL
* @parent: the parent node of the new node
* @value: the int value of the new node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
