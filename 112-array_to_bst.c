#include "binary_trees.h"

/**
* array_to_bst - make a bst from an array
* Return: pointer to root node
* @array: thr int array
* @size: size of the array
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *ret;
	unsigned int i = 0;

	if (!array)
		return (NULL);
	ret = NULL;
	for (; i < size; i++)
	{
		bst_insert(&ret, array[i]);
	}
	return (ret);
}
