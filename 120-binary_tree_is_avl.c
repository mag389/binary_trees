#include "binary_trees.h"
int binary_tree_balance(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
/**
* int binary_tree_is_avl - determines if the tree is an avl tree
* Return: 1 for an avl tree else o
* @tree: the tree to test
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (tree->left && tree->left->n >= tree->n)
		return (0);
	if (tree->right && tree->right->n <= tree->n)
		return (0);
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance > 1 || balance < -1)
		return (0);
	if (tree->right && tree->left)
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
	if (tree->left)
		return (binary_tree_is_avl(tree->left));
	return (binary_tree_is_avl(tree->right));
}
/**
* binary_tree_is_bst - determines if the tree is a bst
* Return: 1 if valid bst else 0
* @tree: the root node to check
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (isleft(tree->left, tree->n) && isright(tree->right, tree->n))
	{
		if (tree->left)
			left = binary_tree_is_bst(tree->left);
		if (tree->right)
			right = binary_tree_is_bst(tree->right);
		return (left && right);
	}
	return (0);
}
/**
* isleft - tests if the left side is < the root
* Return: 1 for valid else 0
* @tree: the tree to check comparison for
* @num: the number to compare against
*/
int isleft(const binary_tree_t *tree, int num)
{
	if (!tree)
		return (1);
	if (tree->n >= num)
		return (0);
	return (isleft(tree->left, num) && isleft(tree->right, num));
}
/**
* isright - tests if the left side is < the root
* Return: 1 for valid else 0
* @tree: the tree to check comparison for
* @num: the number to compare against
*/
int isright(const binary_tree_t *tree, int num)
{
	if (!tree)
		return (1);
	if (tree->n <= num)
		return (0);
	return (isright(tree->left, num) && isright(tree->right, num));
}
/**
* binary_tree_balance - finds balance of the binary tree
* Return: the int balance
* @tree: the root node to test balance of
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
* binary_tree_height - finds the height of the binary tree
* Return: the height as a size_t
* @tree: the root node
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_left > h_right)
		return (1 + h_left);
	return (1 + h_right);
}
