
using System; 
  
class GAURAV  
{ 
public static void printPascal(int n) 
{ 

int[,] arr = new int[n, n];  
  

for (int line = 0; line < n; line++) 
{ 
    
    for (int i = 0; i <= line; i++) 
    { 
 
    if (line == i || i == 0) 
        arr[line, i] = 1; 
    else 
        arr[line, i] = arr[line - 1, i - 1] +  
                       arr[line - 1, i]; 
    Console.Write(arr[line, i]); 
    } 
Console.WriteLine(""); 
} 
} 
  
 
public static void Main ()  
{ 
    int n = 5; 
    printPascal(n); 
} 
} 
  
