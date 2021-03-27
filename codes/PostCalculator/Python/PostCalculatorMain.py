import PostCalculatorModule as pcm

postExp1 = "42*8+"
postExp2 = "123+*4/"

print("{} = {}".format(postExp1, pcm.PostCalculator.EvalRPNExp(postExp1)))
print("{} = {}".format(postExp2, pcm.PostCalculator.EvalRPNExp(postExp2)))
