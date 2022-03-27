#include "binary_trees.h"

/**
 * sorted_array_to_avl - Convert sorted array to an avl binary tree
 *
 * @array: elements of the tree
 * @size: size of the array
 *
 * Return: Value to the tree on succes.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node, *right_node, *left_node;
	size_t half;

	if (size == 0 || !array)
		return (NULL);

	new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return (NULL);

	left_node = NULL;

	half = (size - 1) / 2;
	new_node->n = array[half];
	new_node->parent = NULL;

	if (half > 0)
		left_node = sorted_array_to_avl(array, half);

	else
		left_node = NULL;

	if (size > (half + 1))
		right_node = sorted_array_to_avl(&array[half + 1], size - (half + 1));

	else
		right_node = NULL;

	new_node->left = left_node;
	new_node->right = right_node;

	if (new_node->left)
		(new_node->left)->parent = new_node;

	if (new_node->right)
		(new_node->right)->parent = new_node;

	return (new_node);
}
