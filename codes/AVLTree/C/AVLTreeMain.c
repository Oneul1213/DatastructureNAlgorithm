#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

int main(void)
{
	BTreeNode* avlRoot;
	BTreeNode* currentLeftNode;
	BTreeNode* currentRightNode;
	BSTMakeAndInit(&avlRoot);

	// RR ȸ�� �˻�
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("Level1: %d, %d \n", GetData(currentLeftNode), GetData(currentRightNode));

	currentLeftNode = GetLeftSubTree(GetLeftSubTree(avlRoot));
	currentRightNode = GetRightSubTree(GetLeftSubTree(avlRoot));
	printf("Level2 - Left: %d, %d \n", GetData(currentLeftNode), GetData(currentRightNode));

	currentLeftNode = GetLeftSubTree(GetRightSubTree(avlRoot));
	currentRightNode = GetRightSubTree(GetRightSubTree(avlRoot));
	printf("Level2 - Right: %d, %d \n", GetData(currentLeftNode), GetData(currentRightNode));

	// LLȸ�� �˻�
	/*BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 1);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("����: %d, ������: %d \n", GetData(currentLeftNode), GetData(currentRightNode));*/

	// LR ȸ�� �˻�
	/*BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("����: %d, ������: %d \n", GetData(currentLeftNode), GetData(currentRightNode));*/

	// RL ȸ�� �˻�
	/*BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("����: %d, ������: %d \n", GetData(currentLeftNode), GetData(currentRightNode));*/

	return 0;
}