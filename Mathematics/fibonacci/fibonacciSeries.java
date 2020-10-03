//Using  For Loop
import java.util.Scanner;
public class FibonacciExample {
 
	public static void main(String[] args) 
	{
        Scanner sc=new Scanner(System.in);
		// Set it to the number of elements you want in the Fibonacci Series
		 int maxNumber = sc.nextInt(); 
		 int previousNumber = 0;
		 int nextNumber = 1;
		 
	        System.out.print("Fibonacci Series of "+maxNumber+" numbers:");
 
	        for (int i = 1; i <= maxNumber; ++i)
	        {
	            System.out.print(previousNumber+" ");
	            /* On each iteration, we are assigning second number
	             * to the first number and assigning the sum of last two
	             * numbers to the second number
	             */
 
	            int sum = previousNumber + nextNumber;
	            previousNumber = nextNumber;
	            nextNumber = sum;
	        }
	}
}