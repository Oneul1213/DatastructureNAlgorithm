package DoubleHashTable;

import java.util.function.Function;

public class Table<K, T> {

    private Slot<K, T>[] tbl;
    private Function<K, Integer> hashFunc1;
    private Function<K, Integer> hashFunc2;

    public Table(Function<K, Integer> hf1, Function<K, Integer> hf2) {
        this.tbl = new Slot[Slot.MAX_TBL];

        for (int i = 0; i < Slot.MAX_TBL; i++) {
            this.tbl[i] = new Slot<>();
            this.tbl[i].setStatus(Slot.SlotStatus.EMPTY);
        }

        this.hashFunc1 = hf1;
        this.hashFunc2 = hf2;
    }

    public void TBLInsert(K k, T v) {
        int hv = this.hashFunc1.apply(k);

        // 키가 중복되었다면
        if (TBLSearch(k) != null) {
            System.out.println("키 중복 오류 발생");
            return;
        }

        // 충돌 발생 시 빈 자리를 찾을 때까지 반복
        while (this.tbl[hv].getStatus() == Slot.SlotStatus.INUSE || this.tbl[hv].getStatus() == Slot.SlotStatus.DELETED)
            hv = hv + this.hashFunc2.apply(k);

        this.tbl[hv].setvalue(v);
        this.tbl[hv].setKey(k);
        this.tbl[hv].setStatus(Slot.SlotStatus.INUSE);
    }

    public T TBLDelete(K k) {
        int hv = this.hashFunc1.apply(k);

        // 충돌 발생 시 빈 자리를 찾을 때까지 반복
        while (this.tbl[hv].getStatus() == Slot.SlotStatus.DELETED)
            hv = hv + this.hashFunc2.apply(k);

        if (this.tbl[hv].getStatus() != Slot.SlotStatus.INUSE)
            return null;
        else {
            this.tbl[hv].setStatus(Slot.SlotStatus.DELETED);
            return this.tbl[hv].getValue();
        }
    }

    public T TBLSearch(K k) {
        int hv = this.hashFunc1.apply(k);

        // 충돌 발생 시 빈자리를 찾을 때까지 반복
        while (this.tbl[hv].getStatus() == Slot.SlotStatus.DELETED)
            hv = hv + this.hashFunc2.apply(k);

        if (this.tbl[hv].getStatus() != Slot.SlotStatus.INUSE)
            return null;
        else
            return this.tbl[hv].getValue();
    }
}
