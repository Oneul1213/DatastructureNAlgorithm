package Point;

public class Point implements PointInterface{
    private final int xPos;
    private final int yPos;

    public Point(int xPos, int yPos) {
        this.xPos = xPos;
        this.yPos = yPos;
    }

    public void ShowPointPos() {
        System.out.println("["+this.xPos+", "+this.yPos+"]");
    }

    public int PointComp(Point compPos) {
        if (this.xPos == compPos.xPos && this.yPos == compPos.yPos)
            return 0;
        else if (this.xPos == compPos.xPos)
            return 1;
        else if (this.yPos == compPos.yPos)
            return 2;
        else
            return -1;
    }
}
