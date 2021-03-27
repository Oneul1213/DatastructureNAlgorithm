import ListBaseStackModule as lsm

class PostCalculator:
    @classmethod
    def EvalRPNExp(cls, exp):
        stack = lsm.ListStack()

        for i in range(len(exp)):
            tok = exp[i]

            if tok.isdigit() is True:
                stack.SPush(tok)
            else:
                op2 = stack.SPop()
                op1 = stack.SPop()

                if tok is '+':
                    stack.SPush(int(op1) + int(op2))
                elif tok is '-':
                    stack.SPush(int(op1) - int(op2))
                elif tok is '*':
                    stack.SPush(int(op1) * int(op2))
                elif tok is '/':
                    stack.SPush(int(op1) // int(op2))
        return stack.SPop()