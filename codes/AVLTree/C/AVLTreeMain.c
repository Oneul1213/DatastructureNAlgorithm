#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

int main(void)
{
	BTreeNode* avlRoot;
	BTreeNode* currentLeftNode;
	BTreeNode* currentRightNode;
	BSTMakeAndInit(&avlRoot);

	// RR 회전 검사
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);

	printf("루트 노드: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("Level1: %d, %d \n", GetData(currentLeftNode), GetData(currentRightNode));

	currentLeftNode = GetLeftSubTree(GetLeftSubTree(avlRoot));
	currentRightNode = GetRightSubTree(GetLeftSubTree(avlRoot));
	printf("Level2 - Left: %d, %d \n", GetData(currentLeftNode), GetData(currentRightNode));

	currentLeftNode = GetLeftSubTree(GetRightSubTree(avlRoot));
	currentRightNode = GetRightSubTree(GetRightSubTree(avlRoot));
	printf("Level2 - Right: %d, %d \n", GetData(currentLeftNode), GetData(currentRightNode));

	// LL회전 검사
	/*BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 1);

	printf("루트 노드: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("왼쪽: %d, 오른쪽: %d \n", GetData(currentLeftNode), GetData(currentRightNode));*/

	// LR 회전 검사
	/*BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);

	printf("루트 노드: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("왼쪽: %d, 오른쪽: %d \n", GetData(currentLeftNode), GetData(currentRightNode));*/

	// RL 회전 검사
	/*BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);

	printf("루트 노드: %d \n", GetData(avlRoot));

	currentLeftNode = GetLeftSubTree(avlRoot);
	currentRightNode = GetRightSubTree(avlRoot);
	printf("왼쪽: %d, 오른쪽: %d \n", GetData(currentLeftNode), GetData(currentRightNode));*/

	return 0;
}