#include "binary_trees.h"

/**
 * heap_to_sorted_array -> Write a function that converts a Binary
 *Max Heap to a sorted array of integers
 *
 *@heap: It's a pointer to the root node of the heap to convert
 *@size: It's an address to store the size of the array
 *Return: An array must be sorted in descending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	int ex, b = 0;
	size_t heaps;

	if (!heap)
	{

		return (NULL);

	}	heaps = binary_tre_size(heap);
	*size = heaps;

	arr = malloc(heaps * sizeof(int));

	if (!arr)
	{
		return (NULL);
	}

	while (heap)
	{
		ex = heap_extract(&heap);
		arr[b] = ex;
		b++;

	}	return (arr);
}
