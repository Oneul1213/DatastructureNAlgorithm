package DoubleHashTable;

public class Slot<K, T> {
    final static int MAX_TBL = 100;
    enum SlotStatus { EMPTY, DELETED, INUSE };

    private K key;
    private T value;
    private SlotStatus status;

    public void setKey(K k) {
        this.key = k;
    }

    public K getKey() {
        return this.key;
    }

    public void setvalue(T v) {
        this.value = v;
    }

    public T getValue() {
        return this.value;
    }

    public void setStatus(SlotStatus ss) {
        this.status = ss;
    }

    public SlotStatus getStatus() {
        return this.status;
    }
}
