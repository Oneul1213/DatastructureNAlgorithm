import ListBaseStackModule as lsm

class RPNConverter:
    @classmethod
    def GetOpPrec(cls, op):
        if op is '*' or op is '/':
            return 5
        elif op is '+' or op is '-':
            return 3
        elif op is '(':
            return 1
        else:
            return -1
    
    @classmethod
    def WhoPrecOp(cls, op1, op2):
        op1Prec = cls.GetOpPrec(op1)
        op2Prec = cls.GetOpPrec(op2)

        if op1Prec > op2Prec:
            return 1
        elif op1Prec < op2Prec:
            return -1
        else:
            return 0
    
    @classmethod
    def ConvToRPNExp(cls, exp):
        stack = lsm.ListStack()
        expLen = len(exp)
        convExp = []

        for i in range(expLen):
            tok = exp[i]
            if tok.isdigit() is True:
                convExp.append(tok)
            else:
                if tok is '(':
                    stack.SPush(tok)
                elif tok is ')':
                    while True:
                        popOp = stack.SPop()
                        if popOp is '(':
                            break
                        convExp.append(popOp)
                elif tok is '+' or tok is '-' or tok is '*' or tok is '/':
                    while stack.SIsEmpty() is False and cls.WhoPrecOp(stack.SPeek(), tok) >= 0:
                        convExp.append(stack.SPop())
                    
                    stack.SPush(tok)
        
        while stack.SIsEmpty() is False:
            convExp.append(stack.SPop())
        
        return ''.join(convExp)
