#include "binary_trees.h"

/**
* array_to_avl - makes an avl from an array
* Return: pointer to new root nodeor NULL
* @array: the int array
* @size: size of the int array
*/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root, *temp;
	unsigned int i;

	if (!array || size == 0)
		return (NULL);
	root = NULL;
	for (i = 0; i < size; i++)
	{
		temp = avl_insert(&root, array[i]);
	}
	(void) temp;
	return (root);
}
