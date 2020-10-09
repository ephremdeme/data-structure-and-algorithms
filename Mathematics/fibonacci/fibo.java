import java.util.Scanner;
public class fibo {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of terms :- ");
        int n=sc.nextInt();
        int first=0,sec=1;
        if(n == 0)
            System.exit(0);
        else {
            System.out.print("Fibonacci series is :- "+first);
            for(int i = 0; i < n - 1; i++){
                sec = first + sec;
                first = sec - first;
                System.out.print(" "+first);
            }
        }
        
        
    }
}
