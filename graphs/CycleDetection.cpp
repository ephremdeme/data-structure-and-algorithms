
// Cycle detection in undirected graph using DFS (we can also use BFS)
// Cycle - if there is more than one way to visit any node

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


class Graph {

	int v;
	list<int> *l; //Array of list

public:
	Graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y, bool bidir = true) {
		l[x].push_back(y);
		if (bidir) l[y].push_back(x);
	}

	void printAdjList() {

		for (int i = 0; i < v; i++) {
			cout << i << "-> ";
			for (auto nbr : l[i]) {
				cout << nbr << "_";
			}
			cout << endl;
		}
	}

	bool cycle_helper(int start_node, bool *visited, int parent) {

		visited[start_node] = true;

		for (auto nbr : l[start_node]) {

			if (!visited[nbr]) { //recursively visit the nbr
				return cycle_helper(nbr, visited, start_node);
			}

			else if (nbr != parent) { //nbr is visited but nbr should not be equal to parent
				return true;
			}


		}

		return false;
	}

	bool contains_cycle() {
		bool *visited = new bool[v];
		memset(visited, false, sizeof(visited));

		cycle_helper(0, visited, -1);
	}


};


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	if (g.contains_cycle()) cout << "Cycle exist" << endl;
	else cout << "No cycle present" << endl;


}


