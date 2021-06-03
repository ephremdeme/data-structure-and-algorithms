#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
   if (n == 1)
      return;
   
   for (int i=0; i<n-1; i++) 
      if (arr[i] > arr[i+1]) 
            arr[i] = arr[i] + arr[i+1];
            arr[i+1] = arr[i] - arr[i+1];
            arr[i] = arr[i] - arr[i+1];
   bubbleSort(arr, n-1);
}
void main() {
   int arr[] = {14,1,13,7,50,1,23,20,60};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr, n);   
   cout << "Sorted Sequence is: ";
   for(int i = 0; i <n;i++){
      cout<<arr[i]<<endl;
   }
   getch();
}