#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define iAmInevitable ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//map<ll,ll> freq;
//map<ll,ll> :: iterator itr;
//for(itr=freq.begin();itr!=freq.end();itr++)
//itr->f    itr->s

const int MAX = 1e6+ 5;
typedef pair<ll, ll> PII;
bool marked[MAX];
vector <PII> adj[MAX];

ll prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;   // For creating  minHeap
    ll y;
    ll minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;   //adding Edge Weight
        marked[x] = true;
        for(ll i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
//This Code is Contributed by Amar Shankar
