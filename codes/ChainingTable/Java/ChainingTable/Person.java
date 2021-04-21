package ChainingTable;

public class Person {
    private int ssn;
    private String name;
    private String address;

    public Person() {
        this.ssn = 0;
        this.name = "";
        this.address = "";
    }

    public Person(int _ssn, String _name, String _address) {
        this.ssn = _ssn;
        this.name = _name;
        this.address = _address;
    }

    public int getSsn() {
        return this.ssn;
    }

    public void ShowPerInfo() {
        System.out.println("주민등록번호: "+this.ssn);
        System.out.println("이름: "+this.name);
        System.out.println("주소: "+this.address);
        System.out.println();
    }
}
