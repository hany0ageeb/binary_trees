#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left;

	if (tree == NULL)
		return (NULL);
	left = tree->left;
	tree->left = left->right;
	left->right = tree;
	tree->parent = left;
	left->parent = NULL;
	return (left);
}
