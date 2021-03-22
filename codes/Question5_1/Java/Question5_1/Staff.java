package Question5_1;

public class Staff implements StaffInterface{
    private int o_num;
    private String name;

    public Staff() {
        this.o_num = 0;
        this.name = "";
    }

    public Staff(int o_num, String name) {
        this.o_num = o_num;
        this.name = name;
    }

    public int getO_num() {
        return o_num;
    }

    public String getName() {
        return name;
    }

    public void ShowStaffInfo() {
        System.out.println("사번 : "+this.o_num);
        System.out.println("이름 : "+this.name);
    }
}
