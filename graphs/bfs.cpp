#include<bits/stdc++.h> 

using namespace std;

void bfs(int node,vector<vector<int> > &adjlist,bool visited[]) {
	queue<int> q;
	q.push(node);
	visited[node]=true;
	while(!q.empty()) {
		int n = q.front();
		q.pop();
		cout<<n<<" ";
		for(auto it: adjlist[n]) {
			if(!visited[it]) {
				q.push(it);
				visited[it]=true;
			}
		}
	}
	return;
}

int main() {

	int nodes,edges;
	cin>>nodes>>edges;

	vector<vector<int> > adjlist(nodes+1);

	for(int i=0;i<edges;i++) {
		int src,des;
		cin>>src>>des;
		adjlist[src].push_back(des);
		adjlist[des].push_back(src);
	}

	bool visited[nodes+1];
	for(int i=1;i<=nodes;i++) visited[i]=false;

	for(int i=1;i<=nodes;i++) {
		if(!visited[i]) {
			bfs(i,adjlist,visited);
		}
	}
	return 0;

}