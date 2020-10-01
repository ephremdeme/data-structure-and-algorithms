
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define l long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
  
// Driver program to test above function 
int main() 
{ 
    ll a,b;
    cin>>a>>b;
     cout <<"GCD of " << a << " and "
         << b << " is " << gcd(a, b); 
    cout <<"LCM of " << a << " and "
         << b << " is " << lcm(a, b); 
    return 0; 
} 
