package ArrayList;

public class ArrayList implements ArrayListInterface {
    private int[] arr;
    private int numOfData;
    private int curPosition;

    public ArrayList() {
        this.arr = new int[LIST_LEN];
        this.numOfData = 0;
        this.curPosition = -1;
    }

    @Override
    public void LInsert(int data) {
        if (this.numOfData >= LIST_LEN) {
            System.out.println("저장이 불가능합니다.");
            return;
        }

        this.arr[this.numOfData] = data;
        this.numOfData++;
    }

    @Override
    public boolean LFirst(int[] data) {
        if (this.numOfData == 0)
            return false;

        this.curPosition = 0;
        data[0] = this.arr[0];
        return true;
    }

    @Override
    public boolean LNext(int[] data) {
        if (this.curPosition >= this.numOfData - 1) {
            return false;
        }

        this.curPosition++;
        data[0] = this.arr[this.curPosition];
        return true;
    }

    @Override
    public int LRemove() {
        int rPos = this.curPosition;
        int num = this.numOfData;
        int rdata = this.arr[rPos];

        for (int i = rPos; i < num -1; i++)
            this.arr[i] = this.arr[i+1];

        this.numOfData--;
        this.curPosition--;
        return rdata;
    }

    @Override
    public int LCount() {
        return this.numOfData;
    }
}
