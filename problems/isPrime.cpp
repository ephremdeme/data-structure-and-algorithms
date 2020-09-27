#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int d=2;
    bool divided=false;
    while(d<n)
    {
        if(n%d==0)
        {
            cout<<"False"<<endl;
            divided=true;
        }
        d++;
    }
    if(!divided)
    {
        cout<<"True"<<endl;
    }
}