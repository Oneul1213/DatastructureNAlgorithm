import RPNConverterModule as rcm
import PostCalculatorModule as pcm

class InfixCalculator:
    @classmethod
    def EvalInfixExp(cls, exp):
        expStr = rcm.RPNConverter.ConvToRPNExp(exp)
        
        return pcm.PostCalculator.EvalRPNExp(expStr)
