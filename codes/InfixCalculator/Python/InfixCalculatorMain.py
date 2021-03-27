import InfixCalculatorModule as icm

exp1 = "1+2*3"
exp2 = "(1+2)*3"
exp3 = "((1-2)+3)*(5-2)"

print("{} = {}".format(exp1, icm.InfixCalculator.EvalInfixExp(exp1)))
print("{} = {}".format(exp2, icm.InfixCalculator.EvalInfixExp(exp2)))
print("{} = {}".format(exp3, icm.InfixCalculator.EvalInfixExp(exp3)))
