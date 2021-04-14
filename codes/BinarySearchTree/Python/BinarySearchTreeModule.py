import BinaryTree3Module as btm

class BinarySearchTree:
    def ShowData(self, data):
        print(data, end=' ')
    
    def __init__(self):
        self.root = None
    
    def BSTGetNodeData(self):
        return self.root.GetData()
    
    def BSTInsert(self, data):
        pNode = None
        cNode = self.root

        # 단말 노드가 될 때까지 반복
        while cNode is not None:
            # 키의 중복 방지
            if data is cNode.GetData():
                return
            
            pNode = cNode

            if cNode.GetData() > data:
                cNode = cNode.GetLeftSubTree()
            else:
                cNode = cNode.GetRightSubTree()

        nNode = btm.BinaryTree()
        nNode.SetData(data)

        if pNode is not None:   # 루트 노드가 아닐 경우
            if data < pNode.GetData():
                pNode.MakeLeftSubTree(nNode)
            else:
                pNode.MakeRightSubTree(nNode)
        else:                   # 루트 노드일 경우
            self.root = nNode

    def BSTSearch(self, target):
        cNode = self.root

        while cNode is not None:
            cData = cNode.GetData()

            if target is cNode.GetData():
                return cNode
            elif target < cNode.GetData():
                cNode = cNode.GetLeftSubTree()
            else:
                cNode = cNode.GetRightSubTree()
        
        # target을 찾지 못한 경우
        return None
    
    def BSTRemove(self, target):
        pVRoot = btm.BinaryTree()   # 가상 루트 노드
        pNode = pVRoot              # 부모 노드
        cNode = self.root           # 자식 노드
        dNode = None                # 삭제 대상 노드

        pVRoot.ChangeRightSubTree(self.root)

        # pNode, cNode를 갱신하며 target 찾기
        while cNode is not None and cNode.GetData() is not target:
            pNode = cNode

            if target < cNode.GetData():
                cNode = cNode.GetLeftSubTree()
            else:
                cNode = cNode.GetRightSubTree()
        
        # target을 찾지 못한 경우
        if cNode is None:
            return None
        
        dNode = cNode

        # 삭제할 노드가 단말 노드인 경우
        if dNode.GetLeftSubTree() is None and dNode.GetRightSubTree() is None:
            if pNode.GetLeftSubTree() is dNode:
                pNode.RemoveLeftSubTree()
            else:
                pNode.RemoveRightSubTree()
        
        # 삭제할 노드가 자식 노드 하나를 갖는 경우
        elif dNode.GetLeftSubTree() is None or dNode.GetRightSubTree() is None:
            dcNode = None

            if dNode.GetLeftSubTree() is not None:  # 왼쪽 자식을 갖는 경우
                dcNode = dNode.GetLeftSubTree()
            else:                                   # 오른쪽 자식을 갖는 경우
                dcNode = dNode.GetRightSubTree()
            
            # 자식 노드를 삭제할 노드의 부모 노드에 연결
            if pNode.GetLeftSubTree() is dNode:
                pNode.ChangeLeftSubTree(dcNode)
            else:
                pNode.ChangeRightSubTree(dcNode)
        
        # 삭제할 노드가 여러 자식을 갖는 경우
        else:
            mNode = dNode.GetRightSubTree() # 삭제할 노드를 대체할 노드
            mpNode = dNode                  # mNode의 부모 노드

            # 삭제할 노드를 대체할 노드는 오른쪽 서브 트리 중 가장 작은 값을 갖는 것
            while mNode.GetLeftSubTree() is not None:
                mpNode = mNode
                mNode = mNode.GetLeftSubTree()
            
            delData = dNode.GetData()
            dNode.SetData(mNode.GetData())

            # mNode의 자식 노드를 부모 노드와 연결
            if mpNode.GetLeftSubTree() is mNode:
                mpNode.ChangeLeftSubTree(mNode.GetRightSubTree())
            else:
                mpNode.ChangeRightSubTree(mNode.GetRightSubTree())
            
            # 대체가 끝난 mNode를 삭제 대상으로 지정
            dNode = mNode
            dNode.SetData(delData)
        
        # 루트 노드가 변경되었을 경우 root가 루트 노드를 가리키도록
        if pVRoot.GetRightSubTree() is not self.root:
            self.root = pVRoot.GetRightSubTree()
        
        return dNode
    
    def BSTShowAll(self):
        self.root.InorderTraverse(self.ShowData)
