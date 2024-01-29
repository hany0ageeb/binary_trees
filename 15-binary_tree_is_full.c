#include "binary_trees.h"

/**
 * binary_tree_is_full -  checks if a binary tree is full
 * every parent node/internal node has either two or no children
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or not full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
