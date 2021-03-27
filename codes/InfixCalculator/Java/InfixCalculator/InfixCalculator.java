package InfixCalculator;

public interface InfixCalculator {
    static int EvalInfixExp(char exp[]) {
        int len = exp.length;
        int ret;
        char[] expcpy =  exp.clone();

        expcpy = RPNConverter.ConvToRPNExp(expcpy).toCharArray();
        ret = PostCalculator.EvalRPNExp(expcpy);
        return ret;
    }
}
