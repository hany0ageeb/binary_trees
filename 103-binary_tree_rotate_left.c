#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return:  pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right;

	if (tree == NULL)
		return (NULL);
	right = tree->right;
	tree->right = right->left;
	right->left = tree;
	tree->parent = right;
	right->parent = NULL;
	return (right);
}
