/* This c++ program uses Basic Euclidean algorithm to find greatest common factor(GCD) and lowest common multiple(LCM) of two numbers a and b    entered by user 
   LCM(a,b) = a*b/GCD(a,b)
*/

#include<bits/stdc++.h>
using namespace std;

 long long greatest_common_factor(long long a,long long b)
 {
     if(a == 0){
         return b;
     }
     greatest_common_factor(b%a,a);
 }
 long long lowest_common_multiple(long long a,long long b)
 {
     return ( (a*b)/greatest_common_factor(a,b) );
 }
 int main()
 {
     long long a,b;
     cin >> a >> b;
     long long gcd = greatest_common_factor(a,b);
     long long lcm = lowest_common_multiple(a,b);
     cout<<"GCD of " << a << " and " << b <<" is " << gcd <<" and LCM is " << lcm <<"\n";
     return 0;
 }