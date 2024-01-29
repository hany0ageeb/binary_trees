#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (node);
	node = malloc(sizeof(binary_tree_t));
	if (node != NULL)
	{
		node->n = value;
		node->right = NULL;
		node->parent = parent;
		if (parent->left == NULL)
		{
			parent->left = node;
			node->left = NULL;
		}
		else
		{
			node->left = parent->left;
			parent->left->parent = node;
			parent->left = node;
		}
	}
	return (node);
}
