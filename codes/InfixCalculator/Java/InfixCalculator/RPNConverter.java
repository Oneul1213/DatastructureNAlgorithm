package InfixCalculator;

import InfixToPostfix.ListStack;

public interface RPNConverter {
    private static int GetOpPrec(char op) {
        switch (op) {
            case '*':
            case '/':
                return 5;
            case '+':
            case '-':
                return 3;
            case '(':
                return 1;
        }

        return -1;
    }

    private static int WhoPrecOp(char op1, char op2) {
        int op1Prec = RPNConverter.GetOpPrec(op1);
        int op2Prec = RPNConverter.GetOpPrec(op2);

        if (op1Prec > op2Prec)
            return 1;
        else if (op1Prec < op2Prec)
            return -1;
        else
            return 0;
    }

    static String ConvToRPNExp(char[] exp) {
        ListStack<Character> stack = new ListStack<>();

        int expLen = exp.length;
        char[] convExp = new char[expLen+1];

        int idx = 0;
        char tok, popOp;

        for (int i = 0; i < expLen; i++) {
            tok = exp[i];
            if (Character.isDigit(tok)) {
                convExp[idx++] = tok;
            } else {
                switch (tok) {
                    case '(':
                        stack.SPush(tok);
                        break;

                    case ')':
                        while (true) {
                            popOp = stack.SPop();
                            if (popOp == '(')
                                break;
                            convExp[idx++] = popOp;
                        }
                        break;

                    case '+': case '-':
                    case '*': case '/':
                        while(!stack.SIsEmpty() && RPNConverter.WhoPrecOp(stack.SPeek(), tok) >= 0)
                            convExp[idx++] = stack.SPop();

                        stack.SPush(tok);
                        break;
                }
            }
        }

        while (!stack.SIsEmpty())
            convExp[idx++] = stack.SPop();

        return String.valueOf(convExp).trim();
    }
}
