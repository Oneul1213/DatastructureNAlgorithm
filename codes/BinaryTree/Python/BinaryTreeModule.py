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
