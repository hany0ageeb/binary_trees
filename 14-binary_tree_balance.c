#include "binary_trees.h"

/**
 * b_tree_height - measure the heighht of binary tree
 * @tree: the tree to measur its height
 * Return: the height of tree or 0 if tree is NULL
 */
static int b_tree_height(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	l_height = b_tree_height(tree->left);
	r_height = b_tree_height(tree->right);
	if (l_height > r_height)
		return (l_height + 1);
	return (r_height + 1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * balance factor is calculated by subtructing the height of left
 * tree - height of right tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: 0 if tree is NULL otherwise balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_tree_height = 0, right_tree_height = 0, balance_factor = 0;

	if (tree == NULL)
		return (0);
	left_tree_height = b_tree_height(tree->left);
	right_tree_height = b_tree_height(tree->right);
	balance_factor = left_tree_height - right_tree_height;
	return (balance_factor);
}
