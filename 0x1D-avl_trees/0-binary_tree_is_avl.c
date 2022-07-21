#include "binary_trees.h"

/**
 * is_valid_avl - Check if a given tree is a valid avl tree
 *
 * @tree: head node of a tree
 * @min: minimun value of a subtree
 * @max: maximun value of a subtree
 * @height: height of the tree
 *
 * Return: 1 on valid avl, 0 otherwise
 */
int is_valid_avl(const binary_tree_t *tree, int *height, int min, int max)
{
	int height_left = 0, height_right = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (is_valid_avl(tree->left, &height_left, min, tree->n) == 0 ||
	    is_valid_avl(tree->right, &height_right, tree->n, max) == 0)
		return (0);

	*height = ((height_left > height_right) ? height_left : height_right) + 1;

	if (abs(height_left - height_right) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - check if a given tree is a valid AVL tree
 * @tree: head node of a tree
 * Return: 1 if a given tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, &height, INT_MIN, INT_MAX));
}
