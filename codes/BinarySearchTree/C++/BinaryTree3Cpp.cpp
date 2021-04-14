#include <iostream>
#include <functional>
#include "BinaryTree3Cpp.h"

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

template <typename T> BinaryTree<T>* BinaryTree<T>::RemoveLeftSubTree()
{
	BinaryTree<T>* delNode = this->left;
	this->left = NULL;

	return delNode;
}

template <typename T> BinaryTree<T>* BinaryTree<T>::RemoveRightSubTree()
{
	BinaryTree<T>* delNode = this->right;
	this->right = NULL;

	return delNode;
}

template <typename T> void BinaryTree<T>::ChangeLeftSubTree(BinaryTree<T>* sub)
{
	this->left = sub;
}

template <typename T> void BinaryTree<T>::ChangeRightSubTree(BinaryTree<T>* sub)
{
	this->right = sub;
}