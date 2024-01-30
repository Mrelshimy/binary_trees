#include "binary_trees.h"

/**
 * binary_tree_leaves - function to count binary tree leaves
 *
 * @tree: pointer to root of the tree
 * Return: tree leaves count, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_count = 0;

	if (tree)
	{
		if (!tree->right && !tree->left)
			return (1);
		leaves_count = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
		return (leaves_count);
	}

	return (0);
}
