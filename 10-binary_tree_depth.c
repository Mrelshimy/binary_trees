#include "binary_trees.h"

/**
 * binary_tree_depth - function to calculate binary tree node depth
 *
 * @tree: pointer to root of the tree to traverse
 * Return: tree depth, 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree)
	{
		while (tree->parent)
		{
			node_depth++;
			tree = tree->parent;
		}
		return (node_depth);
	}
	return (0);
}
