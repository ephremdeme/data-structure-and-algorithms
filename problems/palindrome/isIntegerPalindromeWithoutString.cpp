#include<bits/stdc++.h>
using namespace std;

bool solve(long int n)
{
    long int orig_n = n;
    stack<long int>st;
    while(n > 0)
    {
        long int tmp = n%10;
        st.push(tmp);
        n = n/10;
    }
    n = orig_n;
    while(n > 0)
    {
        long int tmp = n%10;
        if(tmp != st.top())
        return false;

        st.pop();
        n = n/10;
    }
    return true;
}

int main()
{
    long int n;
    cin>>n;

    if(solve(n))
    cout<<"PALINDROME"<<endl;
    else
    cout<<"NOT A PALINDROME"<<endl;
    return 0;
}