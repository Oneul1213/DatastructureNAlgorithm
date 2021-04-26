from enum import Enum
import SinglyLinkedListModule as slm
import ArrayBaseStackModule as asm
import PriorityQueueModule as pqm


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

class Edge:
    def __init__(self, _v1, _v2, _weight):
        self.v1 = _v1
        self.v2 = _v2
        self.weight = _weight

class ALGraph:
    def __init__(self, nv):
        self.numV = nv
        self.numE = 0
        self.adjList = []
        self.visitInfo = []
        self.pqueue = pqm.PriorityQueue(lambda d1, d2: d1.weight - d2.weight)

        for i in range(nv):
            self.adjList.append(slm.SinglyLinkedList())
            self.adjList[len(self.adjList) - 1].SetSortRule(lambda d1, d2: d1.value-d2.value)

            self.visitInfo.append(0)

    def VisitVertex(self, visitV):
        if self.visitInfo[visitV.value] is 0:
            self.visitInfo[visitV.value] = 1
            #print(chr(visitV.value + 65), end=' ')
            return True
        return False

    def RecoverEdge(self, fromV, toV, weight):
        self.adjList[fromV.value].LInsert(toV)
        self.adjList[toV.value].LInsert(fromV)

        self.numE += 1
    
    def RemoveWayEdge(self, fromV, toV):
        data = self.adjList[fromV.value].LFirst()
        if data[0] is True:
            if data[1] is toV:
                self.adjList[fromV.value].LRemove()
                return
            
            data = self.adjList[fromV.value].LNext()
            while data[0] is True:
                if data[1] is toV:
                    self.adjList[fromV.value].LRemove()
                    return
                data = self.adjList[fromV.value].LNext()

    def IsConnVertex(self, v1, v2):
        stack = asm.ArrayStack()
        visitV = v1

        self.VisitVertex(visitV)
        stack.SPush(visitV)

        data = self.adjList[visitV.value].LFirst()
        while data[0] is True:
            visitFlag = False

            # 연결된 정점을 찾았다면
            if data[1] is v2:
                # 초기화 후 반환
                self.visitInfo = [0] * self.numV
                return True
            
            if self.VisitVertex(data[1]) is True:
                stack.SPush(visitV)
                visitV = data[1]
                visitFlag = True
            else:
                data = self.adjList[visitV.value].LNext()
                while data[0] is True:
                    # 연결된 정점을 찾았다면
                    if data[1] is v2:
                        # 초기화 후 반환
                        self.visitInfo = [0] * self.numV
                        return True

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
        return False                            # 연결된 정점을 못찾았음

    def RemoveEdge(self, fromV, toV):
        self.RemoveWayEdge(fromV, toV)
        self.RemoveWayEdge(toV, fromV)
        self.numE -= 1

    def AddEdge(self, fromV, toV, weight):
        edge = Edge(fromV, toV, weight)

        self.adjList[fromV.value].LInsert(toV)
        self.adjList[toV.value].LInsert(fromV)

        self.numE += 1

        self.pqueue.PEnqueue(edge)
    
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

    def ConKruskalMST(self):
        recvEdge = []
        
        # MST가 될 때까지 반복
        while self.numE + 1 > self.numV:
            edge = self.pqueue.PDequeue()
            self.RemoveEdge(edge.v1, edge.v2)

            if self.IsConnVertex(edge.v1, edge.v2) is not True:
                self.RecoverEdge(edge.v1, edge.v2, edge.weight)
                recvEdge.append(edge)
        
        for i, e in enumerate(recvEdge):
            self.pqueue.PEnqueue(e)
    
    def ShowGraphEdgeWeightInfo(self):
        copyPQ = self.pqueue

        while copyPQ.PQIsEmpty() is not True:
            edge = copyPQ.PDequeue()
            print("({}-{}) w: {}".format(chr(edge.v1.value + 65), chr(edge.v2.value + 65), edge.weight))
