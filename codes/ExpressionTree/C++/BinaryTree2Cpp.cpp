#include <iostream>
#include <functional>
#include "BinaryTree2Cpp.h"

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

template <typename T> void BinaryTree<T>::PreorderTraverse(std::function<void(T)> action)
{
	if (this == NULL)
		return;

	action(this->data);
	this->left->PreorderTraverse(action);
	this->right->PreorderTraverse(action);
}

template <typename T> void BinaryTree<T>::InorderTraverse(std::function<void(T)> action)
{
	if (this == NULL)
		return;

	this->left->InorderTraverse(action);
	action(this->data);
	this->right->InorderTraverse(action);
}

template <typename T> void BinaryTree<T>::PostorderTraverse(std::function<void(T)> action)
{
	if (this == NULL)
		return;

	this->left->PostorderTraverse(action);
	this->right->PostorderTraverse(action);
	action(this->data);
}

template <typename T> void BinaryTree<T>::DeleteTree()
{
	if (this == NULL)
		return;

	this->left->DeleteTree();
	this->right->DeleteTree();
	free(this);
}