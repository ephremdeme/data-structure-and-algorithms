/* Greatest common divisor using euclidean method */

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

int main(){
    int a,b;
    cout>>"Enter two number : ";
    cin>>a>>b;
    cout<<"GCD of "<<a<<"and "<<b<<"is "<<gcd(a,b);
} 