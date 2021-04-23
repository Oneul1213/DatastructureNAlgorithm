from enum import Enum
import SinglyLinkedListModule as slm


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

        for i in range(nv):
            self.adjList.append(slm.SinglyLinkedList())
            self.adjList[len(self.adjList) - 1].SetSortRule(lambda d1, d2: d1.value-d2.value)
    
    def AddEdge(self, fromV, toV):
        self.adjList[fromV.value].LInsert(toV)
        self.adjList[toV.value].LInsert(fromV)

        self.numE += 1
    
    def ShowGraphEdgeInfo(self):
        for i, e in enumerate(self.adjList):
            print("{}와 연결된 정점:".format(chr(i+65)), end=' ')

            data = self.adjList[i].LFirst()
            if data[0] is True:
                print(chr(data[1].value+65), end=' ')
                data = self.adjList[i].LNext()
                while data[0] is True:
                    print(chr(data[1].value+65), end=' ')
                    data = self.adjList[i].LNext()
            print()
