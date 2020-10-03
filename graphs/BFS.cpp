#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

template<typename T>
class Graph {

	map<T, list<T>> m;

public:

	void addEdge(T x, T y) {
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void bfs(T src) {

		map<T, bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {

			T node = q.front();
			cout << node << " ";
			q.pop();

			for (auto nbr : m[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

};


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfs(0);


	return 0;

}

