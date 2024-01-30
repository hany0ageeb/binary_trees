#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals
 * to value otherwise NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value > tree->n)
		node = tree->right;
	else
		node = tree->left;
	while (node != NULL)
	{
		if (value == node->n)
			return (node);
		else if (value > node->n)
			node = node->right;
		else if (value < node->n)
			node = node->left;
	}
	return (NULL);
}
