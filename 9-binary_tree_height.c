#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * The height of a node in a binary tree is: 
 * the largest number of edges in a path from a leaf node to a target node
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL otherwise height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}
