package PostCalculator;

import java.util.Arrays;

public class PostCalculatorMain {
    public static void main(String[] args) {
        String postExp1 = "42*8+";
        String postExp2 = "123+*4/";

        System.out.println(postExp1+" = "+PostCalculator.EvalRPNExp(postExp1.toCharArray()));
        System.out.println(postExp2+" = "+PostCalculator.EvalRPNExp(postExp2.toCharArray()));
    }
}
