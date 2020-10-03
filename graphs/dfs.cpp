#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int currentNode, vector< vector<int> > &adj, vector<bool> &visited) {
    visited[currentNode] = true;
    cout << currentNode << " ";
    for(int i = 0; i < adj[currentNode].size(); i++) {
        int neighbour = adj[currentNode][i];
        if(!visited[neighbour])
            dfsUtil(neighbour, adj, visited);
    }
    return;
}

void dfs(int nodes, vector< vector<int> > &adj) {
    vector<bool> visited(nodes+1, false);
    for(int i = 1; i <= nodes; i++) {
        if(!visited[i])
            dfsUtil(i, adj, visited);
    }
    return;
}


int main() {
    int nodes, edges, x, y;
    cout <<  "Input number of nodes and edges: ";
    cin >> nodes >> edges;
    cout << "Input edges: \n";
    vector< vector<int> > adj(nodes+1);
    for(int i = 1; i <= edges; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 
    dfs(nodes, adj);
    return 0;
}