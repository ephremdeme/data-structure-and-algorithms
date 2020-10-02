#include <iostream>

using namespace std;


class Kadane{
 public:
     int max_sum(int p[],int n){
        int max_sum=p[0],max_in=p[0];
        for(int i=1;i<n;i++){
           max_sum = max(p[i],max_sum+p[i]);
           max_in = max(max_in,max_sum);
        }
        return max_in;
     }

     void display(int p[],int n){
     cout<<"Element in array "<<endl;
     for(int i=0;i<n;i++){
     cout<<p[i]<<" ";
    }
   }
};


int main()
{
   Kadane algo;
   int n;
   cout<<"Enter the size of array ";
   cin>>n;
   int p[n];
   for (int i=0;i<n;i++){
    cout<<"Enter the element in array ";
    cin>>p[i];
   }
   algo.display(p,n);
   int a = algo.max_sum(p,n);
   cout<<"\n Largest sum of subarray using kadane algorithm is "<<a;
   return 0;
}
