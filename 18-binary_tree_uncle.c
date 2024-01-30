#include "binary_trees.h"

/**
 * binary_tree_uncle - finds binary tree node uncle
 *
 * @node: pointer to node to find the uncle
 * Return: pointer to node uncle, 0 if node is null or no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent && node->parent->parent)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		if (node->parent->parent->right == node->parent)
			return (node->parent->parent->left);
		return (NULL);
	}
	return (NULL);
}
