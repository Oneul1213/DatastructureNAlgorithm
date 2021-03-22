package Question5_1;

public class Question5_1 {
    public static Staff WhoIsOnDutyNext(CircularLinkedList<Staff> list, String name, int days_later) {
        Staff[] staff = new Staff[1];

        if (list.LFirst(staff)) {
            if (staff[0].getName().equals(name)) {
                for (int i = 0; i < days_later; i++)
                    list.LNext(staff);
                return staff[0];
            }

        }

        while(true) {
            list.LNext(staff);
            if (staff[0].getName().equals(name)) {
                for (int i = 0; i < days_later; i++)
                    list.LNext(staff);
                return staff[0];
            }

        }
    }

    public static void main(String[] args) {
        CircularLinkedList<Staff> list = new CircularLinkedList<Staff>();

        // 4명의 사원 정보 저장
        list.LInsert(new Staff(2201036, "정바름"));
        list.LInsert(new Staff(2003014, "나유연"));
        list.LInsert(new Staff(1903048, "구아름"));
        list.LInsert(new Staff(2003075, "신재현"));

        // 누구 당직인지 확인
        WhoIsOnDutyNext(list, "정바름", 6).ShowStaffInfo();
    }
}
