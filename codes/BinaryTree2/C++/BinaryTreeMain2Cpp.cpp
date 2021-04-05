#include <iostream>
#include "BinaryTree2Cpp.h"
#include "BinaryTree2Cpp.cpp"

void ShowIntData(int data);

int main(void)
{
	BinaryTree<int>* bt1 = new BinaryTree<int>();
	BinaryTree<int>* bt2 = new BinaryTree<int>();
	BinaryTree<int>* bt3 = new BinaryTree<int>();
	BinaryTree<int>* bt4 = new BinaryTree<int>();
	BinaryTree<int>* bt5 = new BinaryTree<int>();
	BinaryTree<int>* bt6 = new BinaryTree<int>();

	bt1->SetData(1);
	bt2->SetData(2);
	bt3->SetData(3);
	bt4->SetData(4);
	bt5->SetData(5);
	bt6->SetData(6);

	bt1->MakeLeftSubTree(bt2);
	bt1->MakeRightSubTree(bt3);
	bt2->MakeLeftSubTree(bt4);
	bt2->MakeRightSubTree(bt5);
	bt3->MakeRightSubTree(bt6);

	bt1->PreorderTraverse(ShowIntData);
	std::cout << std::endl;
	bt1->InorderTraverse(ShowIntData);
	std::cout << std::endl;
	bt1->PostorderTraverse(ShowIntData);
	std::cout << std::endl;

	bt3->DeleteTree();
	return 0;
}

void ShowIntData(int data)
{
	std::cout << data << " ";
}