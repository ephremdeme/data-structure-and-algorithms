#include <bits/stdc++.h> 
using namespace std; 
  
// Function to perform Ternary Search 
int ternarySearch(int l, int r, int key, int ar[]) 
{ 
    if (r >= l) { 
  
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
  
        if (ar[mid1] == key)  
            return mid1; 
         
        if (ar[mid2] == key)  
            return mid2; 
        
        if (key < ar[mid1]) 
            return ternarySearch(l, mid1 - 1, key, ar); 
        else if (key > ar[mid2])     
			return ternarySearch(mid2 + 1, r, key, ar);    
        else
			return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
    } 
    return -1; 
} 
int main() 
{ 
    int l, r, p, key; 
  
    int arr[] = { 1, 2, 3, 4, 6, 10, 10, 15, 18, 19, 20 };  
    l = 0;  
    r = 12;
    key = 5; 
  	p = ternarySearch(l, r, key, arr); 
  	cout << "Index of " << key << " is " << p << endl; 
  	key = 20; 
  	p = ternarySearch(l, r, key, arr); 
  
     
    cout << "Index of " << key 
         << " is " << p << endl; 
} 
