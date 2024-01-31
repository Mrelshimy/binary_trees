#include "binary_trees.h"

/**
 * bst_insert - inserts node to BST
 *
 * @tree: pointer to root of the tree to traverse
 * @value: node value
 * Return: pointer to inserted node , NULL if failed
 */

bst_t *bst_insert(bst_t **tree, int value)
{	
	bst_t *new_node = NULL;
	bst_t *new_node_pointer = NULL;

	if (tree)
	{
		if (*tree == NULL)
		{
			*tree = binary_tree_node(NULL, value);
			return (*tree);
		}

		new_node_pointer = *tree;
		while (new_node_pointer)
		{
			if (new_node_pointer->n == value)
				return (NULL);
			if (new_node_pointer->n > value)
			{
				if (new_node_pointer->left == NULL)
				{
					new_node = binary_tree_node(new_node_pointer, value);
					new_node_pointer->left = new_node;
					return (new_node);
				}
				new_node_pointer = new_node_pointer->left;
			}
			if (new_node_pointer->n < value)
			{
				if (new_node_pointer->right == NULL)
				{
					new_node = binary_tree_node(new_node_pointer, value);
					new_node_pointer->right = new_node;
					return (new_node);
				}
				new_node_pointer = new_node_pointer->right;
			}

		}
	}
	return (NULL);
}
