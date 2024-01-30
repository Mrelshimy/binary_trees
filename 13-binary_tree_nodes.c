#include "binary_trees.h"

/**
 * binary_tree_nodes - function to calculate binary tree nodes
 *
 * @tree: pointer to root of the tree
 * Return: tree height
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || !(tree->left || tree->right))
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
