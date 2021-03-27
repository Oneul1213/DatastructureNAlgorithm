package InfixCalculator;

public class InfixCalculatorMain {
    public static void main(String[] args) {
        String exp1 = "1+2*3";
        String exp2 = "(1+2)*3";
        String exp3 = "((1-2)+3)*(5-2)";

        System.out.println(exp1+" = "+InfixCalculator.EvalInfixExp(exp1.toCharArray()));
        System.out.println(exp2+" = "+InfixCalculator.EvalInfixExp(exp2.toCharArray()));
        System.out.println(exp3+" = "+InfixCalculator.EvalInfixExp(exp3.toCharArray()));
    }
}
