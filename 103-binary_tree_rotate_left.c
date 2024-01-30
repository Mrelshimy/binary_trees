#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotate a binary tree
 *
 * @tree: pointer to root of the tree to traverse
 * Return: Pinter to root of rotated tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (tree && tree->right)
	{
		new_tree = tree->right;
		tree->right = new_tree->left;
		new_tree->left = tree;
		new_tree->parent = tree->parent;
		tree->parent = new_tree;
		return (new_tree);
	}
	return (NULL);
}
