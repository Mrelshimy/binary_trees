#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserting node as right child to other node
 *
 * @parent: pointer to new node's parent
 * @value: Value inside node
 * Return: pointer to the new node, NULL at memory allocation failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	if (parent->right)
		parent->right->parent = new_node;

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = parent->right;
	parent->right = new_node;

	return (new_node);
}
