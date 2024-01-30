#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right rotate a binary tree
 *
 * @tree: pointer to root of the tree to traverse
 * Return: Pinter to root of rotated tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (tree && tree->left)
	{
		new_tree = tree->left;
		tree->left = new_tree->right;
		if (tree->left)
			tree->left->parent = tree;
		new_tree->right = tree;
		new_tree->parent = tree->parent;
		tree->parent = new_tree;
		return (new_tree);
	}
	return (NULL);
}
