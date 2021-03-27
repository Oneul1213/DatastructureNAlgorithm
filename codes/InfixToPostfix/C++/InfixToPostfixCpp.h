#ifndef __INFIX_TO_POSTFIX_CPP_H__
#define __INFIX_TO_POSTFIX_CPP_H__

class RPNConverter
{
private:
	static int GetOpPrec(char op);
	static int WhoPrecOp(char op1, char op2);
public:
	static void ConvToRPNExp(char exp[]);
};

#endif