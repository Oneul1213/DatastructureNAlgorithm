from enum import Enum
import SinglyLinkedListModule as slm
import ArrayBaseStackModule as asm
import CircularQueueModule as cqm


class Vertex(Enum):
    A = 0
    B = 1
    C = 2
    D = 3
    E = 4
    F = 5
    G = 6
    H = 7
    I = 8
    J = 9

class ALGraph:
    def __init__(self, nv):
        self.numV = nv
        self.numE = 0
        self.adjList = []
        self.visitInfo = []

        for i in range(nv):
            self.adjList.append(slm.SinglyLinkedList())
            self.adjList[len(self.adjList) - 1].SetSortRule(lambda d1, d2: d1.value-d2.value)

            self.visitInfo.append(0)

    def VisitVertex(self, visitV):
        if self.visitInfo[visitV.value] is 0:
            self.visitInfo[visitV.value] = 1
            print(chr(visitV.value + 65), end=' ')
            return True
        return False

    def AddEdge(self, fromV, toV):
        self.adjList[fromV.value].LInsert(toV)
        self.adjList[toV.value].LInsert(fromV)

        self.numE += 1
    
    def ShowGraphEdgeInfo(self):
        for i, e in enumerate(self.adjList):
            print("{}와 연결된 정점:".format(chr(i + 65)), end=' ')

            data = self.adjList[i].LFirst()
            if data[0] is True:
                print(chr(data[1].value + 65), end=' ')
                data = self.adjList[i].LNext()
                while data[0] is True:
                    print(chr(data[1].value + 65), end=' ')
                    data = self.adjList[i].LNext()
            print()
    
    def DFShowGraphVertex(self, startV):
        stack = asm.ArrayStack()
        visitV = startV

        self.VisitVertex(visitV)
        stack.SPush(visitV)

        data = self.adjList[visitV.value].LFirst()
        while data[0] is True:
            visitFlag = False

            if self.VisitVertex(data[1]) is True:
                stack.SPush(visitV)
                visitV = data[1]
                visitFlag = True
            else:
                data = self.adjList[visitV.value].LNext()
                while data[0] is True:
                    if self.VisitVertex(data[1]) is True:
                        stack.SPush(visitV)
                        visitV = data[1]
                        visitFlag = True
                        break
                    data = self.adjList[visitV.value].LNext()
            
            if visitFlag is False:
                if stack.SIsEmpty() is True:    # 처음 정점으로 돌아왔다면
                    break
                else:
                    visitV = stack.SPop()       # 돌아갈 정점
            
            data = self.adjList[visitV.value].LFirst()

        self.visitInfo = [0] * self.numV
    
    def BFShowGraphVertex(self, startV):
        queue = cqm.CircularQueue()
        visitV = startV

        self.VisitVertex(visitV)

        data = self.adjList[visitV.value].LFirst()
        while data[0] is True:
            if self.VisitVertex(data[1]) is True:
                queue.Enqueue(data[1])
            
            data = self.adjList[visitV.value].LNext()
            while data[0] is True:
                if self.VisitVertex(data[1]) is True:
                    queue.Enqueue(data[1])
                data = self.adjList[visitV.value].LNext()
            
            if queue.QIsEmpty() is True:    # 모든 정점을 다 방문했다면
                break
            else:
                visitV = queue.Dequeue()    # 연결된 다른 정점에서 다시 시작
            
            data = self.adjList[visitV.value].LFirst()

        self.visitInfo = [0] * self.numV
