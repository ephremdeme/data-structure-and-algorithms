#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[100][1000];
    int n;
    cin>>n;

    cin.get(); //to get the extra enter followed after n

    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],1000);
    }

    cout<<"stored in linear Char Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

/*
output
5
helllo
world
how
are
you
stored in linear Char Array
helllo world how are you
*/
