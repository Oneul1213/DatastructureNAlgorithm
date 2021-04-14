#include <iostream>
#include <cstdlib>
#include "BinarySearchTreeCpp.h"
#include "BinarySearchTreeCpp.cpp"

int main(void)
{
	BinarySearchTree<int>* bstRoot = new BinarySearchTree<int>();
	BinaryTree<int>* sNode;

	bstRoot->BSTInsert(5); bstRoot->BSTInsert(8);
	bstRoot->BSTInsert(1); bstRoot->BSTInsert(6);
	bstRoot->BSTInsert(4); bstRoot->BSTInsert(9);
	bstRoot->BSTInsert(3); bstRoot->BSTInsert(2);
	bstRoot->BSTInsert(7);
	
	bstRoot->BSTShowAll(); std::cout << std::endl;
	sNode = bstRoot->BSTRemove(3);
	free(sNode);

	bstRoot->BSTShowAll(); std::cout << std::endl;
	sNode = bstRoot->BSTRemove(8);
	free(sNode);

	bstRoot->BSTShowAll(); std::cout << std::endl;
	sNode = bstRoot->BSTRemove(1);
	free(sNode);

	bstRoot->BSTShowAll(); std::cout << std::endl;
	sNode = bstRoot->BSTRemove(6);
	free(sNode);

	bstRoot->BSTShowAll(); std::cout << std::endl;
	return 0;
}