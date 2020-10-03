#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

//Dijstra's SSSP
//for weighted graph with no negative cycle
//for unweighted graph we have BFS

template<typename T>
class Graph {

	unordered_map<T, list < pair<T, int> >> m;
	//or use map keys will be sorted

public:
	void addEdge(T u, T v, int dist, bool bidir = true) {

		m[u].push_back({v, dist});
		if (bidir) m[v].push_back({u, dist});

	}

	void PrintAdj() {

		for (auto j : m) {
			cout << j.first << "->";
			for (auto l : j.second) {
				cout << "(" << l.first << "," << l.second << ")";
			}
			cout << endl;
		}

	}

	void DijstraSSPS(T src) {

		unordered_map < T, int> dist;

		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}

		//set to find out a node with minimum distance
		set < pair<int, T> >s;  // by deafult set sorts according to first parameter :)

		dist[src] = 0;
		s.insert({0, src});

		while (!s.empty()) {
			//find the pair at the front

			auto p = *(s.begin());  //s.begin() is a pointer so dereferenced
			T node = p.second;
			int nodeDist = p.first;

			s.erase(s.begin());

			//iterate over neighbours
			for (auto neighbour : m[node]) {

				if (dist[neighbour.first] > nodeDist + neighbour.second) {


					T dest = neighbour.first;
					auto f = s.find({dist[dest], dest});
					if (f != s.end()) {
						s.erase(f);
					}

					dist[dest] = nodeDist + neighbour.second;
					s.insert({dist[dest], dest});

				}


			}


		}

		for (auto d : dist) {
			cout << d.first << " is located at distance of " << d.second << endl;
		}




	}


};



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	// Graph<int> g;
	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 4);
	// g.addEdge(2, 3, 1);
	// g.addEdge(3, 4, 2);
	// g.addEdge(1, 4, 7);

	// g.DijstraSSPS(1);

	Graph<int> g;
	g.addEdge(1, 2, 11);
	g.addEdge(1, 3, 5);
	g.addEdge(2, 4, 3);
	g.addEdge(2, 5, 14);

	// g.PrintAdj();
	g.DijstraSSPS(1);

}






