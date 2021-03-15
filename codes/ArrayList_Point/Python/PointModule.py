class Point:
    def __init__(self, xpos, ypos):
        self.xpos = xpos
        self.ypos = ypos
    
    def ShowPointPos(self):
        print("[{}, {}]".format(self.xpos, self.ypos))
    
    def PointComp(self, compPoint):
        if self.xpos == compPoint.xpos and self.ypos == compPoint.ypos:
            return 0
        elif self.xpos == compPoint.xpos:
            return 1
        elif self.ypos == compPoint.ypos:
            return 2
        else:
            return -1
