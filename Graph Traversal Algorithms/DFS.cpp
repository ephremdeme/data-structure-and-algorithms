// DFS using C++

#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<vector<int>> g;

void dfs(int x){
    stack<int> t;
    int y;
    s[x]=true;
    t.push(x);
    while(!t.empty()){
        y=t.top();
        cout<<y<<" ";
        t.pop();
        for(auto i:g[y]){
            if(!s[i]){
                s[i]=true;
                t.push(i);
            }
        }
    }
}


int main() {
	
	int i,x,y,v,e;
	cin>>v>>e;
	g.assign(v,vector<int>());
	s.assign(v,false);
	for(i=0;i<e;i++){
	    cin>>x>>y;
	    g[x].push_back(y);
	}
	for(i=0;i<v;i++){
	    if(!s[i])dfs(i);
	}
	
	return 0;
}