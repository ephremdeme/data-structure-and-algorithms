#include<iostream>
using namespace std;

int main() {
    int limit, no1 = 0, no2 = 1;
    cout<<"Enter the number of terms :- ";
    cin>>limit;
    cout<<"Fibonacci series upto "<<limit<<" elements is :- "<<endl;
    if(limit == 0) 
        return 0;
    else {
        cout<<no1<<"\t";
        for(int i = 0; i < limit - 1; i++) {
            no2 = no1 + no2;
            no1 = no2 - no1;
            cout<<no1<<"\t";
        }
    }   
    return 0;
}