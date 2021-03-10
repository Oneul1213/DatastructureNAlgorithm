class Fibo {
    int Fibo(int n){
        if(n==1)
            return 0;
        else if(n==2)
            return 1;
        else
            return Fibo(n-1) + Fibo(n-2);
    }
}
public class FibonacciFunc {
    public static void main(String[] args) {
        Fibo f = new Fibo();

        for (int i = 1; i < 15; i++)
            System.out.print(f.Fibo(i)+" ");
    }
}
