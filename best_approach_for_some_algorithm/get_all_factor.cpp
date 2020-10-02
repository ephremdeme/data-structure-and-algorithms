// time complexity of this algo is sqrt(n);
/*
	written by pankaj kumar.
*/
#include<algorithm>
#include<string.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpl;
typedef vector<string> vs;
typedef set<string> ss;
typedef set<int> si;
typedef set<ll> sl;
typedef set<pair<int,int>> spi;
typedef set<pair<ll,ll>> spl;
// macros
#define pan cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
#define mod 1000000007;
#define phi 1.618
#define line cout<<endl;
/* ascii value 
A=65,Z=90,a=97,z=122
*/

int main()
{
	int a,count=0;
	cout<<"Enter two number : ";
	cin>>a;
	cout<<"List of all factor of "<<a<<"is : ";
	for(int i=1;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			if(a/i==i)
			{
				count++;
				cout<<i<<" ";
			}
			else
			{
				count+=2;
				cout<<a/i<<" "<<i<<" ";
			}
		}
	}
	line;
	cout<<"Hence total no of factor of "<<a<<" is "<<count<<endl;
}