#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool checkPangram(string str){
    vector<bool> check(26, false);
    int index, len=str.length();

    for(int i = 0; i<len; i++)
    {
        if(str>='A' && str<='Z')
          index = str[i]-'A';
        else if(str[i] >= 'a' && str[i]<='z')
          index = str[i]-'a';
        check[index] = true;
    }
    for(int i=0; i<=25; i++)
       if(!check[i])
         return false;
    return true;
}
int main(){
    string str="The quick brown fox jumps over the lazy dog";

    if(checkPangram(str))cout <<"\""<<str<<"\""<<"is a pangram."<<endl;
    else
    cout<<"\""<<str<<"\""<<"is not a pangram."<<endl;

    return 0;
}

