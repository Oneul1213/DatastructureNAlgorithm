#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	// 단말 노드가 될 때까지 반복
	while (cNode != NULL)
	{
		// 키의 중복 방지
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)		// 루트 노드가 아닐 경우
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else		// 루트 노드일 경우
	{
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;
	
	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// target을 찾지 못한 경우
	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();		// 가상 루트 노드(코드의 일관성을 위함)
	BTreeNode* pNode = pVRoot;					// 부모 노드
	BTreeNode* cNode = *pRoot;					// 자식 노드
	BTreeNode* dNode;							// 삭제 대상 노드

	ChangeRightSubTree(pVRoot, *pRoot);

	// pNode, cNode를 갱신하며 target 찾기
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// target을 찾지 못한 경우
	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	// 삭제할 노드가 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 삭제할 노드가 자식 노드 하나를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode;

		if (GetLeftSubTree(dNode) != NULL)		// 왼쪽 자식을 갖는 경우
			dcNode = GetLeftSubTree(dNode);
		else									// 오른쪽 자식을 갖는 경우
			dcNode = GetRightSubTree(dNode);

		// 자식 노드를 삭제할 노드의 부모 노드에 연결
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// 삭제할 노드가 여러 자식 노드를 갖는 경우
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);		// 삭제될 노드를 대체할 노드
		BTreeNode* mpNode = dNode;						// mNode의 부모 노드
		int delData;

		// 삭제할 노드를 대체할 노드는 오른쪽 서브 트리의 노드 중 가장 작은 값을 갖는 것
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));		// 삭제 노드 대체

		// mNode의 자식 노드를 부모 노드와 연결
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		// 대체가 끝난 mNode를 삭제 대상으로 지정
		dNode = mNode;
		SetData(dNode, delData);
	}

	// 루트 노드가 변경되었을 경우 pRoot가 루트 노드를 가리키도록
	if (GetRightSubTree(pVRoot) != *pRoot)
		* pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}