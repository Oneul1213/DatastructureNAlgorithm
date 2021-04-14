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

	// 단말 노드가 될 때까지 반복
	while (cNode != NULL)
	{
		// 키의 중복 방지
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

	if (pNode != NULL)		// 루트 노드가 아닐 경우
	{
		if (data < pNode->GetData())
			pNode->MakeLeftSubTree(nNode);
		else
			pNode->MakeRightSubTree(nNode);
	}
	else		// 루트 노드일 경우
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

	// target을 찾지 못한 경우
	return NULL;
}

template <typename T> BinaryTree<T>* BinarySearchTree<T>::BSTRemove(T target)
{
	BinaryTree<T>* pVRoot = new BinaryTree<T>();	// 가상 루트 노드(코드의 일관성을 위함)
	BinaryTree<T>* pNode = pVRoot;					// 부모 노드
	BinaryTree<T>* cNode = this->root;				// 자식 노드
	BinaryTree<T>* dNode;							// 삭제 대상 노드

	pVRoot->ChangeRightSubTree(this->root);

	// pNode, cNode를 갱신하며 target 찾기
	while (cNode != NULL && cNode->GetData() != target)
	{
		pNode = cNode;

		if (target < cNode->GetData())
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	// target을 찾지 못한 경우
	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	// 삭제할 노드가 단말 노드인 경우
	if (dNode->GetLeftSubTree() == NULL && dNode->GetRightSubTree() == NULL)
	{
		if (pNode->GetLeftSubTree() == dNode)
			pNode->RemoveLeftSubTree();
		else
			pNode->RemoveRightSubTree();
	}

	// 삭제할 노드가 자식 노드 하나를 갖는 경우
	else if (dNode->GetLeftSubTree() == NULL || dNode->GetRightSubTree() == NULL)
	{
		BinaryTree<T>* dcNode;

		if (dNode->GetLeftSubTree() != NULL)		// 왼쪽 자식을 갖는 경우
			dcNode = dNode->GetLeftSubTree();
		else									// 오른쪽 자식을 갖는 경우
			dcNode = dNode->GetRightSubTree();

		// 자식 노드를 삭제할 노드의 부모 노드에 연결
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}

	// 삭제할 노드가 여러 자식 노드를 갖는 경우
	else
	{
		BinaryTree<T>* mNode = dNode->GetRightSubTree();	// 삭제될 노드를 대체할 노드
		BinaryTree<T>* mpNode = dNode;						// mNode의 부모 노드
		T delData;

		// 삭제할 노드를 대체할 노드는 오른쪽 서브 트리의 노드 중 가장 작은 값을 갖는 것
		while (mNode->GetLeftSubTree() != NULL)
		{
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		delData = dNode->GetData();
		dNode->SetData(mNode->GetData());		// 삭제 노드 대체

		// mNode의 자식 노드를 부모 노드와 연결
		if (mpNode->GetLeftSubTree() == mNode)
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		// 대체가 끝난 mNode를 삭제 대상으로 지정
		dNode = mNode;
		dNode->SetData(delData);
	}

	// 루트 노드가 변경되었을 경우 pRoot가 루트 노드를 가리키도록
	if (pVRoot->GetRightSubTree() != this->root)
		this->root = pVRoot->GetRightSubTree();

	free(pVRoot);
	return dNode;
}

template <typename T> void BinarySearchTree<T>::BSTShowAll()
{
	this->root->InorderTraverse(BinarySearchTree<T>::ShowData);
}