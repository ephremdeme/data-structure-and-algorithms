
//Java program to evaluate fibonacci series 

import java.util.Scanner;

public class Fibonacci{
	public static void main(String args[]){
		Scanner inp = new Scanner(System.in);
		int term = inp.nextInt();
		int first =1, second = 1, temp_first=1;
		while(first<=term){
			System.out.print(first+" ");
			temp_first = first;
			first = second;
			second += temp_first;
			
		}
	}
}