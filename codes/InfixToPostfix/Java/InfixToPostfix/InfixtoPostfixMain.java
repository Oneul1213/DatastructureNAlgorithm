package InfixToPostfix;

public class InfixtoPostfixMain {
    public static void main(String[] args) {
        char[] exp1 = "1+2*3".toCharArray();
        char[] exp2 = "(1+2)*3".toCharArray();
        char[] exp3 = "((1-2)+3)*(5-2)".toCharArray();

        System.out.println(RPNConverter.ConvToRPNExp(exp1));
        System.out.println(RPNConverter.ConvToRPNExp(exp2));
        System.out.println(RPNConverter.ConvToRPNExp(exp3));
    }
}
