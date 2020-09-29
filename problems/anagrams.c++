#include<iostream>
#include<algorithm>
#include<string.h>
#define Chars 256
bool Check(char* s1, char* s2) 
{ 
    
    int count[Chars] = { 0 }; 
    int i; 
  
    for (i = 0; s1[i] && s2[i]; i++) { 
        count[s1[i]]++; 
        count[s2[i]]--; 
    } 
  
    if (s1[i] || s2[i]) 
        return false; 
  
    // See if there is any non-zero value in count array 
    for (i = 0; i < Chars ; i++) 
        if (count[i]) 
            return false; 
    return true; 
} 