package fibonacci;

public class Fibonacci {

    public static void main(String[] args) {
        int max = Integer.parseInt(args[0]);
        fib(max);
    }

    static void fib(int n){
        int fib1 = 0;
        int fib2 = 1;
        while (fib2 <= n){
            System.out.println(fib2);
            int temp = fib2;
            fib2 = temp + fib1;
            fib1 = temp;
        }
    }


}
