#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    bool divided=false;
    if(n%2==0){
        divided=true;
    }
    else{
        int d=3;
        while(d*d<n){
            if(n%d==0){
                divided=true;
                break;
            }
            d+=2;
        }
    }
    if(!divided){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}