#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 *
 * @tree: pointer to root of the tree
 * Return: balance factor, 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{	
	if (tree)
	{
		if (binary_tree_balance(tree) == 0)
			{
				if (binary_tree_leaves(tree->left) ==
				binary_tree_leaves(tree->right))
					return (1);
			}
		return (0);
	}	
	return (0);
}
