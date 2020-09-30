package array;

public class SelectionSort {

	public static void main(String[] args) {
		int a[]= {2,4,-1,15,9,6,-19,100};
		int n=a.length;
		
		for(int i=0 ; i<=n-1 ; i++) {
			
			int minIndex=i;
			for(int j=i ; j<=n-1; j++) {
				
				if(a[j]<a[minIndex]) {
					minIndex=j;
				}
				
			}
			int temp=a[i];
			a[i]=a[minIndex];
			a[minIndex]=temp;
		}
      for(int e: a) {
    	  System.out.print(e+"  ");
      }
	}

}
