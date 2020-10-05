#include<bits/stdc++.h>
using namespace std;
int findFirstDuplicate(int arr[])
{
    int sizeOfArray=sizeof(arr)/sizeof(arr[0]);
    unordered_set<int> store;
    for(int i=0;i<sizeOfArray;i++)
    {
      if(store.find(arr[i])!= store.end())
      {
         return arr[i];
      }
      store.insert(arr[i]);
    }
    return -1;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<findFirstDuplicate(arr);
    return 0;
}
