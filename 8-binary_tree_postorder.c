#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_postorder - goes through a binary tree using post-order
 * traversal i.e. left->right->root
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
