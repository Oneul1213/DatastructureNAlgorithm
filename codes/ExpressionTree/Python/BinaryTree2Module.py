class BinaryTree:
    def __init__(self):
        self.left = None
        self.right = None
        self.data = None
    
    def GetData(self):
        return self.data
    
    def SetData(self, data):
        self.data = data
    
    def GetLeftSubTree(self):
        return self.left
    
    def GetRightSubTree(self):
        return self.right
    
    def MakeLeftSubTree(self, sub):
        self.left = sub
    
    def MakeRightSubTree(self, sub):
        self.right = sub
    
    def PreorderTraverse(self, action):
        action(self.data)
        if self.left is not None:
            self.left.PreorderTraverse(action)
        if self.right is not None:
            self.right.PreorderTraverse(action)
    
    def InorderTraverse(self, action):
        if self.left is not None:
            self.left.InorderTraverse(action)
        action(self.data)
        if self.right is not None:
            self.right.InorderTraverse(action)
    
    def PostorderTraverse(self, action):
        if self.left is not None:
            self.left.PostorderTraverse(action)
        if self.right is not None:
            self.right.PostorderTraverse(action)
        action(self.data)