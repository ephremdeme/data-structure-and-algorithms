#include<bits/stdc++.h>
using namespace std;
int maximum(int a,int b);
void initialiseSets(vector<int> &parent, vector<int> &size, multiset<int> &sizesOfSets,int n)
{
 for(int i = 1;i <= n;i++)
    {
  parent[i] = i;
  size[i] = 1;
  sizesOfSets.insert(1);
    }
}

int findParent(int camper, vector<int> &parent)
{
 if(parent[camper] == camper) return camper;
 return parent[camper] = findParent(parent[camper], parent);
}

void setUnion(int camper1,int camper2, vector<int> &parent, vector<int> &size, multiset<int> &sizesOfSets)
{
 int parent1 = findParent(camper1,parent);
 int parent2 = findParent(camper2,parent);
 if(parent1 != parent2)
    {
  parent[parent1] = parent2;
  sizesOfSets.erase(sizesOfSets.find(size[parent1]));
  sizesOfSets.erase(sizesOfSets.find(size[parent2]));
  size[parent2] += size[parent1];
  sizesOfSets.insert(size[parent2]);
 }
}

vector<int> findSolution(vector< pair<int,int> > &queries, int n)
{
vector<int> parent(n+1);
vector<int> size(n+1);
multiset<int> sizesOfSets;

initialiseSets(parent,size,sizesOfSets,n);

int numberOfQueries = queries.size();
vector<int> ans;
for(int i = 0;i < numberOfQueries;i++) {
 int camper1 = queries[i].first;
 int camper2 = queries[i].second;
 setUnion(camper1,camper2,parent,size,sizesOfSets);
 ans.push_back(*(--sizesOfSets.end()) - *sizesOfSets.begin());
}
return ans;
}
int main() {
    int i,j,k,l,m,n,t,q;
    cin >> n >> q;
    vector< pair<int,int> > queries;
    while(q--) {
        int u,v;
        cin >> u >> v;
        queries.push_back({u,v});
    }
    vector<int> ans = findSolution(queries,n);
    for(int an : ans) {
        cout << an << endl;
    }
   
}
