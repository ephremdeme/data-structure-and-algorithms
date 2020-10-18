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
const ll MAX = 1e6 + 5;
typedef pair<ll, ll> PII;
ll id[MAX],rank1[MAX] ,nodes, edges;
pair <ll, PII > p[MAX];
// Time Complexity O(ElogV)

void initialize()
{
    for(ll i = 0;i < MAX;++i)
        {
            id[i] = i;
            rank1[i]=0; //  or memset(rank,0,sizeof(rank))
        }
}

// A utility function to find set of an element i 
// (uses path compression technique) 
ll findRoot(ll x)
{
     // find root and make root as parent of x  and evrything else in the path
    //  path compression 
    if(id[x] != x)
    {
        id[x] = findRoot(id[x]);
    }
    return id[x];
}
// A function that does union of two sets of x and y 
// (uses union by rank) 
void union1(ll x, ll y) 
{ 
    ll xroot = findRoot(x); 
    ll yroot = findRoot(y); 
  
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank) 
    if (rank1[xroot] < rank1[yroot]) 
        id[xroot]= yroot;
    else if (rank1[xroot]  >  rank1[yroot]) 
         id[yroot] = xroot ; 
  
    // If ranks are same, then make one as root and  
    // increment its rank by one 
    else
    { 
        id[yroot] = xroot ; 
        rank1[xroot] ++; 
    } 
} 


long long kruskal(pair<ll, PII > p[])
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(findRoot(x) != findRoot(y))
        {  //if not add the edges to the minimum spanning trees. 
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    iAmInevitable;
    ll x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = mp(weight, mp(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}

//This Code is Contributed by Amar Shankar
