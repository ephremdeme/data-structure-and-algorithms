#include<bits/stdc++.h>
using namespace std;

bool check(long int a, long int b, vector<pair<long int, long int> >vp)
{
    //cout<<"inside check"<<endl;
    //cout<<"size of vp "<<vp.size()<<endl;
    long int size = vp.size();
    for(long int i=0;i<=size-1;i++)
    {
        //cout<<"inside loop"<<endl;
        if(vp[i].first == a || vp[i].second == b)
        return false;

        if(abs(a-vp[i].first) == abs(b-vp[i].second))
        return false;
    }
    return true;
}

bool recur_fill(long int a, long int b, vector<pair<long int, long int> >&vp, long int n)
{
if(b == n && a < n)
return false;
if(a == n)
return true;
bool result = check(a, b, vp);
if(result == true)
{
    vp.push_back(make_pair(a, b));
    bool val = recur_fill(a+1, 0, vp, n);
    if(val == false)
    {
    pair<long int, long int>tmp = vp.back();
    vp.pop_back();
    return recur_fill(tmp.first, tmp.second+1, vp, n);
    }
}
else
{
    return recur_fill(a, b+1, vp, n);
}

return true;
}

int main()
{
vector<pair<long int, long int> >vp;
vp.clear();
long int n;
cin>>n;
recur_fill(0, 0, vp, n);
for(long int i=0;i<=vp.size()-1;i++)
{
    long int c = vp[i].second;
    for(long int j=0;j<c;j++)
    {
        cout<<" * ";
    }
    cout<<" Q ";
    for(long int j=c+1;j<n;j++)
    {
        cout<<" * ";
    }
    cout<<endl;
}
}