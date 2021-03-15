package Question3_1;

public class Qustion3_1 {
    public static void main(String[] args) {
        // 리스트 초기화
        ArrayList list = new ArrayList();

        // 정수 1~9 리스트에 저장
        for (int i = 1; i<10; i++)
            list.LInsert(i);

        // 리스트 순차 참조 후 저장된 값들의 합 출력
        int[] data = new int[1];
        if(list.LFirst(data)) {
            int cnt = 0;
            cnt += data[0];

            while (list.LNext(data))
                cnt += data[0];
            System.out.println("리스트에 저장된 값의 합 : "+cnt);
        }

        // 리스트에 저장된 값 중 2의 배수, 3의 배수 모두 삭제
        if(list.LFirst(data)) {
            if (data[0] % 2 == 0 || data[0] % 3 == 0)
                list.LRemove();

            while (list.LNext(data))
                if (data[0] % 2 == 0 || data[0] % 3 == 0)
                    list.LRemove();
        }

        // 저장된 데이터를 순서대로 출력
        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while(list.LNext(data))
                System.out.print(data[0]+" ");
        }
        System.out.println();
    }
}
