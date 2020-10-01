public class LinearSearch{    
public static int linearSearch(int[] arr, int key){    
        for(int i=0;i<arr.length;i++){    
            if(arr[i] == key){    
                return i;    
            }    
        }    
        return -1;    
    }    
    public static void main(String args[]){    
        int[] a= {10,20,30,50,70,90};    
        int key = 50;    
        System.out.println(key+" is found at an index: "+linearSearch(a, key));    
    }    
}   