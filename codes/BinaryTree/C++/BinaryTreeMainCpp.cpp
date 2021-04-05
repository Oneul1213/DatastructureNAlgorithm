#include <iostream>
#include "BinaryTreeCpp.h"
#include "BinaryTreeCpp.cpp"

int main(void)
{
	BinaryTree<int>* bt1 = new BinaryTree<int>();
	BinaryTree<int>* bt2 = new BinaryTree<int>();
	BinaryTree<int>* bt3 = new BinaryTree<int>();
	BinaryTree<int>* bt4 = new BinaryTree<int>();

	bt1->SetData(1);
	bt2->SetData(2);
	bt3->SetData(3);
	bt4->SetData(4);

	bt1->MakeLeftSubTree(bt2);
	bt1->MakeRightSubTree(bt3);
	bt2->MakeLeftSubTree(bt4);

	std::cout << bt1->GetLeftSubTree()->GetData() << std::endl;
	std::cout << bt1->GetLeftSubTree()->GetLeftSubTree()->GetData() << std::endl;

	return 0;
}