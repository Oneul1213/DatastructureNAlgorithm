package InfixCalculator;

public interface PostCalculator {
    static int EvalRPNExp(char exp[]) {
        ListStack<Character> stack = new ListStack<Character>();
        int expLen = exp.length;
        char tok, op1, op2;

        for (int i = 0; i < expLen; i++) {
            tok = exp[i];

            if (Character.isDigit(tok)) {
                stack.SPush((char)(tok - '0'));
            } else {
                op2 = stack.SPop();
                op1 = stack.SPop();

                switch (tok) {
                    case '+':
                        stack.SPush((char)((int)op1 + (int)op2));
                        break;
                    case '-':
                        stack.SPush((char)((int)op1 - (int)op2));
                        break;
                    case '*':
                        stack.SPush((char)((int)op1 * (int)op2));
                        break;
                    case '/':
                        stack.SPush((char)((int)op1 / (int)op2));
                        break;
                }
            }
        }
        return stack.SPop();
    }
}
