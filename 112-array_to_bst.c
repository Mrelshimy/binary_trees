#include "binary_trees.h"

/**
 * array_to_bst- construct BST from array
 *
 * @array: pointer to array
 * @size: array size
 * Return: pointer to BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *new_tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&new_tree, array[i]);
	return (new_tree);
}
