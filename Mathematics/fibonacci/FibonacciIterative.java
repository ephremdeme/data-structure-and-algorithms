public class FibonacciIterative {
    public static void main (String[]args) {
        System.out.println (nfib (0)); // Output - 0
        System.out.println (nfib (1)); // Output - 1
        System.out.println (nfib (2)); // Output - 1
        System.out.println (nfib (3)); // Output - 2
        System.out.println (nfib (4)); // Output - 3
        System.out.println (nfib (5)); // Output - 5
    }

    static int nfib (int n) {
        int c = 1;
        int a = 0;
        int b = 1;

    if (n == 0) return 0;

    while (c < n) {
    	b += a;
	    a = b - a;
	    c++;
    }
    return b;
    }
}
