#include "binary_trees.h"

/**
 * array_to_avl - creates an AVL tree from an array
 *
 * @array: array of integers
 * @size: the size of the array
 * Return: pointer to the root of the created tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i = 0;

	while (size > i)
		avl_insert(&root, array[i++]);
	return (root);
}
