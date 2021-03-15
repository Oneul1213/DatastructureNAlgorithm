package Question3_1;

public interface ArrayListInterface {
    int LIST_LEN = 100;

    void LInsert(int data);

    boolean LFirst(int[] data);
    boolean LNext(int[] data);

    int LRemove();
    int LCount();
}
