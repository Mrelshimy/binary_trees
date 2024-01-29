#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a left child node
 * @parent: the parent of the inserted node
 * @value: the value of the new node
 * Return: the new node if created successfully
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent)
		node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	if (parent->left)
		parent->left->parent = node;

	node->n = value;
	node->left = parent->left;
	node->right = NULL;
	node->parent = parent;
	parent->left = node;

	return (node);
}
