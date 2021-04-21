package DoubleHashTable;

public class DoubleHashMain {
    public static int MyHashFunc1(int k) {
        return k % 100;
    }

    public static int MyHashFunc2(int k) {
        return 1 + (k % 7);
    }

    public static void main(String[] args) {
        Table<Integer, Person> myTbl;
        Person np;
        Person sp;
        Person rp;

        myTbl = new Table<>(DoubleHashMain::MyHashFunc1, DoubleHashMain::MyHashFunc2);

        np = new Person(20120003, "LEE", "Seoul");
        myTbl.TBLInsert(np.getSsn(), np);

        np = new Person(20130012, "KIM", "Jeju");
        myTbl.TBLInsert(np.getSsn(), np);

        np = new Person(20170049, "HAN", "Kangwon");
        myTbl.TBLInsert(np.getSsn(), np);

        sp = myTbl.TBLSearch(20120003);
        if (sp != null)
            sp.ShowPerInfo();

        sp = myTbl.TBLSearch(20130012);
        if (sp != null)
            sp.ShowPerInfo();

        sp = myTbl.TBLSearch(20170049);
        if (sp != null)
            sp.ShowPerInfo();

        rp = myTbl.TBLDelete(20120003);
        rp = myTbl.TBLDelete(20130012);
        rp = myTbl.TBLDelete(20170049);
    }
}
