class HanoiTowerMove{
    public void HanoiTowerMove(int num, char from, char by, char to){
        if(num == 1) {
            System.out.println("원반1을 " + from + "에서 " + to + "로 이동");
        } else {
            HanoiTowerMove(num-1, from, to, by);
            System.out.println("원반"+num+"을(를) "+from+"에서 "+to+"로 이동");
            HanoiTowerMove(num-1, by, from, to);
        }
    }
}

public class HanoiTowerSolu {
    public static void main(String[] agrs) {
        HanoiTowerMove htm = new HanoiTowerMove();
        htm.HanoiTowerMove(3, 'A', 'B', 'C');
    }
}
