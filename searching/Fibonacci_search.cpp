#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[100],n,fm,fm1,fm2,i,l;
	cout<<"enter size of array";
	cin>>n;
	cout<<"enter elements";
	for(i=0;i<n;i++)
		cin>>arr[i];
	int s;
	cout<<"enter searched element";
	cin>>s;
	fm1=1;
	fm2=0;
	fm=fm1+fm2;
	while(fm<n){
		
		fm2=fm1;
	    fm1=fm;
		fm=fm1+fm2;
			       
		}   
	int offset=0;
	int flag=0;
	int co=0;
	while(co<=n+1){
		 l=offset+fm2;
		 if(n>l)
		 i=l;
		 else
		 {
			 i=n;
		 }
		if(arr[i]==s)
		{
		cout<<"element found at index "<<i;
			flag=1;
			break;
			co+=1;
		}
		else if(arr[i]>s)
		{
	        fm=fm2;      
			fm1=fm1-fm;    
			fm2=fm-fm1;   
			co+=1;
		}
		else
		{
		fm=fm1;                  
	    fm1=fm2;                 
		fm2=fm-fm1;   
		offset=i;
		co+=1;
		}
	}
	if(arr[0]==s)
	{
		cout<<"found at index 0";
		flag=1;
	}
	if(flag==0)
	{
		cout<<"elem not fnd";
	}
	
}

