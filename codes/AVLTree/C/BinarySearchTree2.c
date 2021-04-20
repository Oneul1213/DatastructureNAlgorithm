#include <stdio.h>
#include <stdlib.h>
#include "AVLRebalance.h"
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

// Rebalancing �ݿ�
BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == NULL)		// ��Ʈ ����� ���
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL;
	}
	return *pRoot;
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

	// target�� ã�� ���� ���
	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();		// ���� ��Ʈ ���(�ڵ��� �ϰ����� ����)
	BTreeNode* pNode = pVRoot;					// �θ� ���
	BTreeNode* cNode = *pRoot;					// �ڽ� ���
	BTreeNode* dNode;							// ���� ��� ���

	ChangeRightSubTree(pVRoot, *pRoot);

	// pNode, cNode�� �����ϸ� target ã��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// target�� ã�� ���� ���
	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	// ������ ��尡 �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// ������ ��尡 �ڽ� ��� �ϳ��� ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode;

		if (GetLeftSubTree(dNode) != NULL)		// ���� �ڽ��� ���� ���
			dcNode = GetLeftSubTree(dNode);
		else									// ������ �ڽ��� ���� ���
			dcNode = GetRightSubTree(dNode);

		// �ڽ� ��带 ������ ����� �θ� ��忡 ����
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// ������ ��尡 ���� �ڽ� ��带 ���� ���
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);		// ������ ��带 ��ü�� ���
		BTreeNode* mpNode = dNode;						// mNode�� �θ� ���
		int delData;

		// ������ ��带 ��ü�� ���� ������ ���� Ʈ���� ��� �� ���� ���� ���� ���� ��
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));		// ���� ��� ��ü

		// mNode�� �ڽ� ��带 �θ� ���� ����
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		// ��ü�� ���� mNode�� ���� ������� ����
		dNode = mNode;
		SetData(dNode, delData);
	}

	// ��Ʈ ��尡 ����Ǿ��� ��� pRoot�� ��Ʈ ��带 ����Ű����
	if (GetRightSubTree(pVRoot) != *pRoot)
		* pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	*pRoot = Rebalance(pRoot);
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