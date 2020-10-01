#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter upto which you want the series: ";
	cin>>n;
	int first = 0;
	int second = 1;
	for(int i = 0; i < n; i++)
	{
		if(first <= n){
		cout<<first<<" ";
		int temp = second;
		second += first;
		first = temp;
		}
	}
	return 0;
}
