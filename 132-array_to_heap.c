#include "binary_trees.h"

/**
* array_to_heap - makes a heap from an array
* Return: the root node of the heap
* @array: the array
* @size: the size of the array
*/
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	if (!array || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}
	return (root);
}
