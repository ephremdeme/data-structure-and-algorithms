#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(int n, vector<int>& A, set<int>& s, vector<int>& curr, vector<vector<int>>& ans)
{
    if (curr.size() == n)
    {
        //cout<<"hi\n";
        ans.push_back(curr);
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(i) == s.end())
        {
            s.insert(i);
            curr.push_back(A[i]);
            solve(n, A, s, curr, ans);
            curr.pop_back();
            s.erase(s.find(i));
        }
    }
}

void permute(vector<int>& A)
{

    vector<vector<int>> ans;
    vector<int> curr;
    set<int> s;
    int n = A.size();
    solve(n, A, s, curr, ans);
    cout << ans.size() << "size\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto x : ans[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {

        cin >> A[i];
    }
    permute(A);
}
