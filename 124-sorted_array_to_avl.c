#include "binary_trees.h"

/**
 * sorted_array_to_avl -> Write a function that builds AVL tree from array
 *@array: It's a pointer to the first element of the array to be converted
 *@size: It's the number of element in the array
 *Return: A pointer to root node of created AVL tree || (NULL)-> failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (!array)
	{

		return (NULL);

	}	return (sorted_avl(array, 0, size - 1, NULL));

}

/**
 * sorted_avl -> Write a function that help sorted_array_to_avl
 *@array: It's a pointer to the first element of the array to be converted
 *@start: The starting item
 *@end: The ending item
 *@parent: It's a pointer to parent of node
 *Return: The new node
 */

avl_t *sorted_avl(int *array, int start, int end, avl_t *parent)
{

	avl_t *nar;
	int ar;

	if (start > end)
	{

		return (NULL);

	}	ar = (start + end) / 2;
	nar = calloc(1, sizeof(avl_t));

	if (!nar)
	{

		return (NULL);

	}	nar->n = array[ar];
	nar->parent = parent;

	nar->left = sorted_avl(array, start, ar - 1, nar);
	nar->right = sorted_avl(array, ar + 1, end, nar);

	return (nar);

}
