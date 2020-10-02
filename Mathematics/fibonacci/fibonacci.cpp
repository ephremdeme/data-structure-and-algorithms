#include<bits/stdc++.h>
using namespace std;

int main() {
    //fibonacci series starting from 1 
    //n>=1
    int n;
    cin>>n;
     int n1 = 1, n2 = 1, fib = 0;
     printf("1 1 ");
    while (fib<n) {
        fib = n1 + n2;
        n1 = n2;
        n2 = fib;
        if(fib<=n)
            printf("%d ", fib);
    }
  return 0;
}
