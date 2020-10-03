# Python3 program to illustrate 
# recursive approach to ternary search 
import math as mt 
  

def ternarySearch(l, r, key, ar): 
  
    if (r >= l): 
  

        mid1 = l + (r - l) //3
        mid2 = r - (r - l) //3
  
     
        if (ar[mid1] == key):  
            return mid1 
          
        if (ar[mid2] == key):  
            return mid2 
          

        if (key < ar[mid1]):  
  
            return ternarySearch(mid1 + 1, r, key, ar) 
          
        elif (key > ar[mid2]):  
  
            return ternarySearch(mid2 + 1, r, key, ar) 
          
        else:  
  
           
            return ternarySearch(mid1 + 1,  
                                 mid2 - 1, key, ar) 
          

    return -1
