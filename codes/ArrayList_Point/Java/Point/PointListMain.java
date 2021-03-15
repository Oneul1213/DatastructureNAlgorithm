package Point;

public class PointListMain {
    public static void main(String[] args) {
        ArrayListGeneric<Point> list = new ArrayListGeneric<Point>();
        Point compPos;
        Point[] pPos = new Point[1];

        list.LInsert(new Point(2, 1));

        list.LInsert(new Point(2, 2));

        list.LInsert(new Point(3, 1));

        list.LInsert(new Point(3, 2));

        System.out.println("현재 저장된 데이터의 수: "+list.LCount());

        if(list.LFirst(pPos)) {
            pPos[0].ShowPointPos();

            while(list.LNext(pPos))
                pPos[0].ShowPointPos();
        }
        System.out.println();

        compPos = new Point(2, 0);

        if(list.LFirst(pPos)) {
            if(pPos[0].PointComp(compPos) == 1)
                list.LRemove();

            while(list.LNext(pPos))
                if(pPos[0].PointComp(compPos) == 1)
                    list.LRemove();
        }

        System.out.println("현재 데이터의 수: "+list.LCount());

        if(list.LFirst(pPos)) {
            pPos[0].ShowPointPos();

            while(list.LNext(pPos))
                pPos[0].ShowPointPos();
        }
    }
}
