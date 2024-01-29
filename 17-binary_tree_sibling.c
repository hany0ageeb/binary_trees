#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * Two nodes are said to be siblings if they are present at the same level,
 * and their parents are the same.
 * @node: a pointer to the node to find the sibling
 * Return: a pointer to a sibling node or
 * NULL if node is NULL or there is no sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left != node)
		return (node->parent->left);
	return (node->parent->right);
}
