#include <bits/stdc++.h>

using namespace  std ; 
vector <bool> vis ; 
vector < vector <int> > adj ; 

void BFS(int s)
{
    queue <int> q ; 
    q.push(s) ;
    vis[s] = true ; 
    while (!q.empty())
    {
        int f = q.front() ; 
        q.pop() ; 
        cout<<f<<" " ; 
        for(auto u : adj[f])
        {
            if(vis[u]==false)
            {
                q.push(u) ; 
                vis[u] = true ; 
            }
        }
    }
    
}

int main()
{   cout<<"Enter number of Nodes and Edges\n" ; 
    int n , e ; 
    cin>>n>>e ; 
    vis.assign(n ,false) ; 
    adj.assign(n , vector <int> ()) ; 
    int x , y ; 
    cout<<"Enter Edges\n" ; 
    for (int i = 0; i < e; i++) { 
        cin>>x>>y ; 
        adj[x].push_back(y)  ; 
        adj[y].push_back(x) ; 
    } 
    cout<<"BFS path from source node 0 : " ;
    BFS(0) ; 
}