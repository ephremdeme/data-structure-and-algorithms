// C++ code to linearly search x in arr[]. If x 
// is present then return its location, otherwise 
// return -1 

#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

int search(int arr[], int n, int x) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		if (arr[i] == x) 
			return i; 
	return -1; 
} 

int main(void) 
{ 

	int searchKey; 
	int numOfElements;
	cin >> numOfElements;
	int arr[numOfElements];
	for(int i=0;i<numOfElements;i++){
	    cin >> arr[i];
	}
	cin >> searchKey;

	int result = search(arr, numOfElements, searchKey); 
    (result == -1)? cout<<"Element is not present in array" : cout<<"Element is present at index " <<result; 
return 0; 
} 
