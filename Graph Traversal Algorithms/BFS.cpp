// BFS code in C++

#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int t=q.front();
        cout<<q.front()<<" ";
        q.pop();
        for(auto i=g[t].begin();i<g[t].end();i++){
            if(!vis[*i]){
                q.push(*i);
                vis[*i]=true;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        vector<bool> vis(N, false);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bfs(0, adj, vis, N);
        cout << endl;
    }
}