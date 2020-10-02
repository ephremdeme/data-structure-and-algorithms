import java.util.Scanner;

public class linearSearch{    
    static int linearSearch(int[] arr, int key){    
        for(int i=0;i<arr.length;i++)    
            if(arr[i] == key)    
                return i;    
        return -1;    
    }    
    public static void main(String args[]){    
        System.out.print("Enter the no: of elements in the array: ");
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int arr[] = new int[50];
        System.out.print("Enter the elements:\n");
        for(int i = 0; i < n; i++)
            arr[i] = scan.nextInt();
        System.out.print("Enter the key: ");
        int key = scan.nextInt();
        scan.close();
        System.out.println(key+" found at an index: "+ linearSearch(arr, key));    
    }    
}   