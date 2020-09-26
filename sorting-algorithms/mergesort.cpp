#include <bits/stdc++.h>
using namespace std;

void mergesort(int* a,int low,int high){
	if(high==low)
		return;
	int mid = low+(high-low)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	int n1 = mid-low+1,n2 = high-mid;
	int left[n1],right[n2];
	for(int i=low;i<=mid;i++){
		left[i-low] = a[i];
	}
	for(int i=mid+1;i<=high;i++){
		right[i-mid-1] = a[i];
	}
	int i=0,j=0,k=low;
	while(i<n1&&j<n2){
		if(left[i]<right[j]){
			a[k] = left[i];k++;i++;
		}
		else{
			a[k] = right[j];k++;j++;
		}
	}
	while(i<n1){
		a[k] = left[i];k++;i++;
	}
	while(j<n2){
		a[k] = right[j];k++;j++;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}