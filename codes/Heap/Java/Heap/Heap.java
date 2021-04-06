package Heap;

public class Heap<T> implements HeapInterface<T>{
    private PriorityComp<T> comp;
    private int numOfData;
    private T[] heapArr;

    private int GetParentIDX(int idx) {
        return idx / 2;
    }

    private int GetLChildIDX(int idx) {
        return idx * 2;
    }

    private int GetRChildIDX(int idx) {
        return this.GetLChildIDX(idx) + 1;
    }

    private int GetHiPriChildIDX(int idx) {
        if (this.GetLChildIDX(idx) > this.numOfData)
            return 0;
        else if (this.GetLChildIDX(idx) == this.numOfData)
            return this.GetLChildIDX(idx);
        else {
            if (this.comp.comp(this.heapArr[this.GetLChildIDX(idx)], this.heapArr[this.GetRChildIDX(idx)]) < 0)
                return this.GetRChildIDX(idx);
            else
                return this.GetLChildIDX(idx);
        }
    }

    @SuppressWarnings("unchecked")
    public Heap(PriorityComp<T> comp) {
        this.comp = comp;
        this.numOfData = 0;
        this.heapArr = (T[])new Object[HEAP_LEN];
    }

    @Override
    public boolean HIsEmpty() {
        if (this.numOfData == 0)
            return true;
        else
            return false;
    }

    @Override
    public void HInsert(T data) {
        int idx = this.numOfData + 1;

        while (idx != 1) {
            if (this.comp.comp(data, this.heapArr[this.GetParentIDX(idx)]) > 0) {
                this.heapArr[idx] = this.heapArr[this.GetParentIDX(idx)];
                idx = this.GetParentIDX(idx);
            } else
                break;;
        }

        this.heapArr[idx] = data;
        this.numOfData += 1;
    }

    @Override
    public T HDelete() {
        T retData = this.heapArr[1];
        T lastElem = this.heapArr[this.numOfData];

        int parentIdx = 1;
        int childIdx;

        while((childIdx = this.GetHiPriChildIDX(parentIdx)) != 0) {
            if (this.comp.comp(lastElem, this.heapArr[childIdx]) >= 0)
                break;

            this.heapArr[parentIdx] = this.heapArr[childIdx];
            parentIdx = childIdx;
        }

        this.heapArr[parentIdx] = lastElem;
        this.numOfData -= 1;
        return retData;
    }
}
