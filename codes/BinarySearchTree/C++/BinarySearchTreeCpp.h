#pragma once

#include <iostream>
#include <cstdlib>
#include "BinaryTree3Cpp.h"
#include "BinaryTree3Cpp.cpp"

template <typename T> class BinarySearchTree
{
private:
	BinaryTree<T>* root;

	static void ShowData(T data)
	{
		std::cout << data << " ";
	}
public:
	BinarySearchTree();
	T BSTGetNodeData();

	void BSTInsert(T data);
	BinaryTree<T>* BSTSearch(T target);
	BinaryTree<T>* BSTRemove(T target);
	
	void BSTShowAll();
};