#pragma once
#include <functional>

template <typename T> class BinaryTree
{
private:
	T data;
	BinaryTree<T>* left;
	BinaryTree<T>* right;
public:
	BinaryTree();
	T GetData();
	void SetData(T data);

	BinaryTree<T>* GetLeftSubTree();
	BinaryTree<T>* GetRightSubTree();

	void MakeLeftSubTree(BinaryTree<T>* sub);
	void MakeRightSubTree(BinaryTree<T>* sub);

	void PreorderTraverse(std::function<void(T)> action);
	void InorderTraverse(std::function<void(T)> action);
	void PostorderTraverse(std::function<void(T)> action);

	void DeleteTree();
};