#include <iostream>
#include "BinaryTreeCpp.h"

template <typename T> BinaryTree<T>::BinaryTree()
{
	this->left = NULL;
	this->right = NULL;
}

template <typename T> T BinaryTree<T>::GetData()
{
	return this->data;
}

template <typename T> void BinaryTree<T>::SetData(T data)
{
	this->data = data;
}

template <typename T> BinaryTree<T>* BinaryTree<T>::GetLeftSubTree()
{
	return this->left;
}

template <typename T> BinaryTree<T>* BinaryTree<T>::GetRightSubTree()
{
	return this->right;
}

template <typename T> void BinaryTree<T>::MakeLeftSubTree(BinaryTree<T>* sub)
{
	if (this->left != NULL)
		free(this->left);

	this->left = sub;
}

template <typename T> void BinaryTree<T>::MakeRightSubTree(BinaryTree<T>* sub)
{
	if (this->right != NULL)
		free(this->right);

	this->right = sub;
}