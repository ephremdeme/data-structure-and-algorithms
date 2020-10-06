package array;
import java.util.*;
public class BubbleSort {

	public static void main(String[] args) {

		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int a[]= new int[n];
		boolean sorted= true;
		for(int i=0; i<=n-1; i++) {
			
			for(int j=0; j<=n-2-i ; j++) {
				
				if(a[j+1]<a[j]) {
					int temp= a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
					sorted=false;
					}
				}
			if(sorted) break;				
			}
		for(int item: a) {
		System.out.print(item+"  ");
			
		}
	}
}
