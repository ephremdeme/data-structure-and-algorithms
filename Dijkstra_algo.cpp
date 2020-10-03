#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define N 1001
using namespace std;
const int INF=1<<29;

int adj[N][N],dis[N];
bool vis[N];

//Implementation of Dijkstra Algorithm
void dijkstra(ll s,ll n)
{
    //Change distance to all nodes except starting node to INF and mark all nodes unvisited
    fill(dis,dis+N,INF);
    fill(vis,vis+N,false);
    ll u,d;
    dis[s]=0;
    for(int i=1;i<n+1;i++)
    {
        u=0;    d=INF;
        for(int j=1;j<n+1;j++)
        {
            if(!vis[j]&&dis[j]<d)
            {
                d=dis[j];
                u=j;
            }
        }
        vis[u]=true;

        for(int j=1;j<n+1;j++)
        {
            if(!vis[j])
                dis[j]=min(dis[j],dis[u]+adj[u][j]);
        }
    }
}

//Printing distance to all nodes from starting node
void print_distance(ll n)
{
    for(int i=1;i<n+1;i++)
    {
        if(vis[i]) cout<<dis[i]<<endl;
        else cout<<"-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x,y,w,n,m;
    cin>>n>>m;
    fill_n(&adj[0][0],N*N,INF);
    for(int i=0,i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x][y]=adj[y][x]=min(adj[x][y],w);
    }
    dijkstra(1,n);

    print_distance(n);

}
