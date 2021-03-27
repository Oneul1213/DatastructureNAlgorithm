import RPNConverterModule as rpn

print(rpn.RPNConverter.ConvToRPNExp("1+2*3"))
print(rpn.RPNConverter.ConvToRPNExp("(1+2)*3"))
print(rpn.RPNConverter.ConvToRPNExp("((1-2)+3)*(5-2)"))
