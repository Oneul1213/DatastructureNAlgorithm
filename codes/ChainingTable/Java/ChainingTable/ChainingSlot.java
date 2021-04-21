package ChainingTable;

public class ChainingSlot<K, T> {
    private K key;
    private T value;

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
}
