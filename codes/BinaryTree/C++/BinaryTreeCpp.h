#pragma once

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
};