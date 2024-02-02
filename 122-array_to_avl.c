#include "binary_trees.h"

/**
 * array_to_avl - inserts node to BST
 *
 * @tree: pointer to root of the tree to traverse
 * @value: node value
 * Return: pointer to inserted node , NULL if failed
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root;
	size_t i = 0;

	while(size > i)
		avl_insert(&root, array[i++]);
    return (root);
}
