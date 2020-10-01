import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	
     Scanner sc = new Scanner(System.in);
     int n= sc.nextInt();
    

        int  a = 1, b = 1;
        
        
        while (a <= n)
        {   
            System.out.print(a+",");

            int sum = a + b;
            a = b;
            b = sum;
        }
    }
}
	

