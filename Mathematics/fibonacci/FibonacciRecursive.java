public class FibonacciRecursive {
    public static void main (String[]args) {
        System.out.println (nfib (0)); // Output - 0
        System.out.println (nfib (1)); // Output - 1
        System.out.println (nfib (2)); // Output - 1
        System.out.println (nfib (3)); // Output - 2
        System.out.println (nfib (4)); // Output - 3
        System.out.println (nfib (5)); // Output - 5
    }

    static int nfib (int n) {

        if (n == 0) return 0;
    
        if (n == 1) return 1;
    
        return nfib(n - 1) + nfib(n - 2);
    }
}
