#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if binary tree is full
 *     meaning all the nodes have either 0 or 2 childs
 *
 * @tree: pointer to root of the tree
 * Return: 1 if full, 0 if not;
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left && tree->right)
		return
			binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right);
	if (tree->left || tree->right)
		return (0);

	return (1);
}
