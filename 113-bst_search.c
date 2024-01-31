#include "binary_trees.h"

/**
 * bst_search - search for a value in BST
 *
 * @tree: pointer to tree
 * @value: value to search for
 * Return: pointer to node containing the value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *search_pointer = NULL;

	if (tree)
	{
		search_pointer = (bst_t *)tree;
		while (search_pointer)
		{
			if (search_pointer->n == value)
				return (search_pointer);
			if (search_pointer->n < value)
				search_pointer = search_pointer->right;
			else
				search_pointer = search_pointer->left;
		}
		
	}
	return (NULL);
}
