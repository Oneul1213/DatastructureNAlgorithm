package Question3_2;

public class NameCard implements NameCardInterface {
    private String name;
    private String phone;

    public NameCard(String name, String phone) {
        this.name = name;
        this.phone = phone;
    }

    @Override
    public void ShowNameCardInfo() {
        System.out.println("이름 : "+ this.name);
        System.out.println("번호 : "+ this.phone);
    }

    @Override
    public boolean NameCompare(String name) {
        return this.name.equals(name);
    }

    @Override
    public void ChangePhoneNum(String phone) {
        this.phone = phone;
    }
}
