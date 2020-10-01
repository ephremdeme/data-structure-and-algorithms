#include<bits/stdc++.h>
#define inf 1e10

using namespace std;

typedef long long int lld;

int main()
{
	lld min, minind, v, e, i, x;

	cout << "\nEnter the number of vertices(numbering starts from 1) and edges:";
	cin >> v >> e;
	cout << "\nEnter source vertex:";
	cin >> x;

	vector<vector<lld> > edge(e, vector<lld>(3));
	vector<vector<pair<lld,lld> > > adj(v + 1);
	vector<lld> vis(v + 1, 0), key(v + 1, inf);
	key[x] = 0;

	cout << "\nEnter edges(vertex numbers of connected vertices) and their weights:";
	for(i = 0; i < e; )
	{
		cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
		if(edge[i][1] > v || edge[i][2] > v)
		{
			cout << "\nInvalid vertex\n";
			continue;
		}

		adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
		adj[edge[i][2]].push_back({edge[i][0], edge[i][1]});
		++i;
	}

	for(i = 0; i < v - 1; ++i)
	{
		min = inf;

		for(lld j = 1; j <= v; ++j)
		{
			if(!vis[j] && key[j] < min)
			{
				min = key[j];
				minind = j;
			}
		}

		vis[minind] = 1;

		for(lld k = 0; k < adj[minind].size(); ++k)
		{
			lld y = adj[minind][k].second;
			lld w = adj[minind][k].first;

			if(!vis[y] && w + key[minind] < key[y])
				key[y] = w + key[minind];
		}
	}

	cout << "\n The following are the shortest path lengths from " << x << " to i(-1 means no path):" << endl;
	for(i = 1; i <= v; ++i)
	{
		cout << "vertex " << i << ": ";
		if(key[i] == inf)
			cout << "NO PATH" << endl;
		else
			cout << key[i] << endl;
	}

	return 0;
}
