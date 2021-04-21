package ChainingTable;

public class ChainingTableMain {
    public static int MyHashFunc(int k) {
        return k % 100;
    }

    public static void main(String[] args) {
        ChainingTable<Integer, Person> myTbl = new ChainingTable<Integer, Person>(ChainingTableMain::MyHashFunc);
        Person np;
        Person sp;
        Person rp;

        np = new Person(900254, "LEE", "Seoul");
        myTbl.TBLInsert(np.getSsn(), np);

        np = new Person(900139, "KIM", "Jeju");
        myTbl.TBLInsert(np.getSsn(), np);

        np = new Person(900827, "HAN", "Kangwon");
        myTbl.TBLInsert(np.getSsn(), np);

        sp = myTbl.TBLSearch(900254);
        if (sp != null)
            sp.ShowPerInfo();

        sp = myTbl.TBLSearch(900139);
        if (sp != null)
            sp.ShowPerInfo();

        sp = myTbl.TBLSearch(900827);
        if (sp != null)
            sp.ShowPerInfo();

        rp = myTbl.TBLDelete(900254);
        rp = myTbl.TBLDelete(900139);
        rp = myTbl.TBLDelete(900827);
    }
}
