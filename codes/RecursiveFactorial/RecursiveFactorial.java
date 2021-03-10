class Factorial {
    public int Factorial(int n)
    {
        if(n == 0)
            return 1;
        else
            return n * Factorial(n-1);
    }
}

public class RecursiveFactorial {
    public static void main(String[] args)
    {
        Factorial f = new Factorial();
        System.out.println("1! = "+f.Factorial(1));
        System.out.println("2! = "+f.Factorial(2));
        System.out.println("3! = "+f.Factorial(3));
        System.out.println("4! = "+f.Factorial(4));
        System.out.println("9! = "+f.Factorial(9));
    }
}
