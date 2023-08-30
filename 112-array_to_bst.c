#include "binary_trees.h"

/**
 * array_to_bst -> Write a function that builds
 *a Binary Search Tree from an array
 *
 *@array: It's a pointer to the first element of the array to be converted
 *@size: It's the number of element in the array
 *Return: A pointer to the root node of the created BST || (NULL) -> failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *rtree = NULL;
	size_t a, b;

	if (array == NULL)
	{
		return (NULL);
	}

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{

			if (array[b] == array[a])

				break;

		}

		if (b == a)
		{

			if (bst_insert(&rtree, array[a]) == NULL)
			{
				return (NULL);
			}
		}
	}	return (rtree);
}
