#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n, rev=0;
        cin>>n;
        while(n>0)
        {
            rev=rev*10+n%10;
            n=n/10;
        }
        cout<<rev<<endl;
    }
	return 0;
}

