#include "binary_trees.h"

/**
* sorted_array_to_avl - makes an avl tree from sorted array
* Return: pointer to root node of avl tree
* @array: sorted array of ints to make into tree
* @size: how many ints are in size
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node;
	unsigned int middle;

	if (!array || size == 0)
		return (NULL);
	middle = size / 2 - (1 - size % 2);

	new_node = binary_tree_node(NULL, array[middle]);

	new_node->left = sorted_array_to_avl(array, middle);
	if (new_node->left)
		new_node->left->parent = new_node;

	new_node->right = sorted_array_to_avl(&array[middle + 1], size / 2);
	if (new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}
