#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a  tree is root
 * @node:  the first node of the tree
 * Return: 1 if the node is at the root of a tree
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent)
		return (0);
	else
		return (1);
}
