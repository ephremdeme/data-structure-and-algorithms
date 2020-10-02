#include <iostream>
using namespace std;
#include <iostream>
using namespace std;


void heapify(int n,int p[],int i)
{
//intilizing root
int root = i;
int left = i*2+1;
int right = i*2+2;


//finding largest element
  if(p[right]>p[root]&& right<n){
    root = right;
  }
  if(p[left]>p[root]&& left<n){
    root = left;
  }
  if(root != i){
    int temp = p[i];
     p[i] = p[root];
     p[root] = temp;


     heapify(n,p,root);

  }
}

void heap_sort(int p[],int n)
{
  //starting heapify from bottom
  for(int i=n/2-1;i>=0;i--){
    heapify(n,p,i);
  }
  //deleting element from heap
  for(int i= n-1;i>0;i--)
  {
     //swaping to the root
     int temp= p[0];
     p[0] = p[i];
     p[i] = temp;
     //now heapify again
     heapify(i,p,0);
  }

}

int main()
{
int n;
cout <<"enter the size of array";
cin >>n;
int p[n];
for(int i=0;i<n;i++){
     cout <<"Enter the element in array : " ;
    cin >>p[i];
}

heap_sort(p,n);

for(int i=0;i<n;i++){
    cout<<p[i]<<" ";
}
return 0;
}





