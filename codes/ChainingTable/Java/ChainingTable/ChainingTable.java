package ChainingTable;

import java.util.function.Function;

public class ChainingTable<K, T> {
    final static int MAX_TBL = 100;

    private SinlgyLinkedList<ChainingSlot<K, T>>[] tbl;
    private Function<K, Integer> hashFunc;

    public ChainingTable(Function<K, Integer> hf) {
        this.tbl = new SinlgyLinkedList[MAX_TBL];

        for (int i = 0; i < MAX_TBL; i++)
            this.tbl[i] = new SinlgyLinkedList<ChainingSlot<K, T>>();

        this.hashFunc = hf;
    }

    public void TBLInsert(K k, T v) {
        int hv = this.hashFunc.apply(k);
        ChainingSlot<K, T> ns = new ChainingSlot<K, T>();
        ns.setKey(k);
        ns.setvalue(v);

        // 키가 중복되었다면
        if (this.TBLSearch(k) != null) {
            System.out.println("키 중복 오류 발생");
            return;
        } else {
            this.tbl[hv].LInsert(ns);
        }
    }

    public T TBLDelete(K k) {
        int hv = this.hashFunc.apply(k);
        ChainingSlot<K, T>[] cSlot = new ChainingSlot[1];

        if (this.tbl[hv].LFirst(cSlot)) {
            if (cSlot[0].getKey().equals(k)) {
                this.tbl[hv].LRemove();
                return cSlot[0].getValue();
            } else {
                while (this.tbl[hv].LNext(cSlot)) {
                    if (cSlot[0].getKey().equals(k)) {
                        this.tbl[hv].LRemove();
                        return cSlot[0].getValue();
                    }
                }
            }
        }

        return null;
    }

    public T TBLSearch(K k) {
        int hv = this.hashFunc.apply(k);
        ChainingSlot<K, T>[] cSlot = new ChainingSlot[1];

        if (this.tbl[hv].LFirst(cSlot)) {
            if (cSlot[0].getKey().equals(k))
                return cSlot[0].getValue();
            else {
                while (this.tbl[hv].LNext(cSlot)) {
                    if (cSlot[0].getKey().equals(k))
                        return cSlot[0].getValue();
                }
            }
        }

        return null;
    }
}
