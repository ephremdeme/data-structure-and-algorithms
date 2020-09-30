#include  <iostream> 
using namespace std; 
  
int shellSort(int arr[], int n) 
{ 
    for (int g = n/2; g > 0; g/= 2) 
    { 
          
        for (int i = g; i < n; i += 1) 
        { 
            
            int temp = arr[i]; 
            
            int j;             
            for (j = i; j >= g && arr[j - g] > temp; j -= g) 
                arr[j] = arr[j - g]; 
              
            
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 
  
int main() 
{ 
    int arr[] = {12, 34, 54, 2, 3}, i; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Array before sorting:"<<endl; 
    printArray(arr, n); 
  
    shellSort(arr, n); 
  
    cout << "\nArray after sorting:"<<endl; 
    printArray(arr, n); 
  
    return 0; 
}