#include <iostream>
#include <functional>
#include "BinarySearchTreeCpp.h"

template <typename T> BinarySearchTree<T>::BinarySearchTree() : root(NULL)
{

}

template <typename T> T BinarySearchTree<T>::BSTGetNodeData()
{
	return this->root->GetData();
}

template <typename T> void BinarySearchTree<T>::BSTInsert(T data)
{
	BinaryTree<T>* pNode = NULL;
	BinaryTree<T>* cNode = this->root;

	// �ܸ� ��尡 �� ������ �ݺ�
	while (cNode != NULL)
	{
		// Ű�� �ߺ� ����
		if (data == cNode->GetData())
			return;

		pNode = cNode;

		if (cNode->GetData() > data)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	BinaryTree<T>* nNode = new BinaryTree<T>();
	nNode->SetData(data);

	if (pNode != NULL)		// ��Ʈ ��尡 �ƴ� ���
	{
		if (data < pNode->GetData())
			pNode->MakeLeftSubTree(nNode);
		else
			pNode->MakeRightSubTree(nNode);
	}
	else		// ��Ʈ ����� ���
	{
		this->root = nNode;
	}
}

template <typename T> BinaryTree<T>* BinarySearchTree<T>::BSTSearch(T target)
{
	BinaryTree<T>* cNode = this->root;

	while (cNode != NULL)
	{
		T cData = cNode->GetData();

		if (target == cData)
			return cNode;
		else if (target < cData)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	// target�� ã�� ���� ���
	return NULL;
}

template <typename T> BinaryTree<T>* BinarySearchTree<T>::BSTRemove(T target)
{
	BinaryTree<T>* pVRoot = new BinaryTree<T>();	// ���� ��Ʈ ���(�ڵ��� �ϰ����� ����)
	BinaryTree<T>* pNode = pVRoot;					// �θ� ���
	BinaryTree<T>* cNode = this->root;				// �ڽ� ���
	BinaryTree<T>* dNode;							// ���� ��� ���

	pVRoot->ChangeRightSubTree(this->root);

	// pNode, cNode�� �����ϸ� target ã��
	while (cNode != NULL && cNode->GetData() != target)
	{
		pNode = cNode;

		if (target < cNode->GetData())
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	// target�� ã�� ���� ���
	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	// ������ ��尡 �ܸ� ����� ���
	if (dNode->GetLeftSubTree() == NULL && dNode->GetRightSubTree() == NULL)
	{
		if (pNode->GetLeftSubTree() == dNode)
			pNode->RemoveLeftSubTree();
		else
			pNode->RemoveRightSubTree();
	}

	// ������ ��尡 �ڽ� ��� �ϳ��� ���� ���
	else if (dNode->GetLeftSubTree() == NULL || dNode->GetRightSubTree() == NULL)
	{
		BinaryTree<T>* dcNode;

		if (dNode->GetLeftSubTree() != NULL)		// ���� �ڽ��� ���� ���
			dcNode = dNode->GetLeftSubTree();
		else									// ������ �ڽ��� ���� ���
			dcNode = dNode->GetRightSubTree();

		// �ڽ� ��带 ������ ����� �θ� ��忡 ����
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}

	// ������ ��尡 ���� �ڽ� ��带 ���� ���
	else
	{
		BinaryTree<T>* mNode = dNode->GetRightSubTree();	// ������ ��带 ��ü�� ���
		BinaryTree<T>* mpNode = dNode;						// mNode�� �θ� ���
		T delData;

		// ������ ��带 ��ü�� ���� ������ ���� Ʈ���� ��� �� ���� ���� ���� ���� ��
		while (mNode->GetLeftSubTree() != NULL)
		{
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		delData = dNode->GetData();
		dNode->SetData(mNode->GetData());		// ���� ��� ��ü

		// mNode�� �ڽ� ��带 �θ� ���� ����
		if (mpNode->GetLeftSubTree() == mNode)
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		// ��ü�� ���� mNode�� ���� ������� ����
		dNode = mNode;
		dNode->SetData(delData);
	}

	// ��Ʈ ��尡 ����Ǿ��� ��� pRoot�� ��Ʈ ��带 ����Ű����
	if (pVRoot->GetRightSubTree() != this->root)
		this->root = pVRoot->GetRightSubTree();

	free(pVRoot);
	return dNode;
}

template <typename T> void BinarySearchTree<T>::BSTShowAll()
{
	this->root->InorderTraverse(BinarySearchTree<T>::ShowData);
}