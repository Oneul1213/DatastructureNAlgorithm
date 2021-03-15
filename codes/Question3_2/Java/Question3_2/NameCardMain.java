package Question3_2;

public class NameCardMain {
    public static void main(String[] args) {
        ArrayListGeneric<NameCard> list = new ArrayListGeneric<NameCard>();
        NameCard[] data = new NameCard[1];

        // 3명의 정보 저장
        list.LInsert(new NameCard("바름", "010-1234-5678"));
        list.LInsert(new NameCard("유연", "010-9123-4567"));
        list.LInsert(new NameCard("재현", "010-8912-3456"));

        // 특정 한 명의 이름 탐색 및 정보 출력
        if (list.LFirst(data)) {
            if (data[0].NameCompare("바름")) {
                data[0].ShowNameCardInfo();

                while(list.LNext(data)) {
                    if(data[0].NameCompare("바름"))
                        data[0].ShowNameCardInfo();
                }
            }
        }
        System.out.println();

        // 특정 한 명의 이름 탐색 및 전화번호 변경
        if (list.LFirst(data)) {
            if (data[0].NameCompare("유연"))
                data[0].ChangePhoneNum("010-7891-2345");

            while(list.LNext(data)) {
                if(data[0].NameCompare("유연"))
                    data[0].ChangePhoneNum("010-7891-2345");
            }
        }

        // 특정 한 명의 이름 탐색 및 삭제
        if (list.LFirst(data)) {
            if (data[0].NameCompare("재현"))
                list.LRemove();

            while(list.LNext(data))
                if(data[0].NameCompare("재현"))
                    list.LRemove();
        }

        // 남아있는 데이터 출력
        if (list.LFirst(data)) {
            data[0].ShowNameCardInfo();

            while(list.LNext(data)) {
                data[0].ShowNameCardInfo();
            }
        }
        System.out.println();
    }
}
