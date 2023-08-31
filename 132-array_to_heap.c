#include "binary_trees.h"

/**
 * array_to_heap -> Write a function to build Max Binary Heap tree from array
 *@array: It's a pointer to the first element of the array to be converted
 *@size: It's the number of element in the array
 *Return: A pointer to root node of created Binary Heap || (NULL)-> failure
 */

heap_t *array_to_heap(int *array, size_t size)
{

	size_t b = 0;
	bst_t *ronde = NULL;

	if (!array)
	{

		return (NULL);

	}

	while (b < size)
	{

		heap_insert(&ronde, array[b]);
		b++;

	}	return (ronde);

}
