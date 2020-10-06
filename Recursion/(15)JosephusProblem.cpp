#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define endl "\n"

// IBH Recursion
// Josephus Problem | Game of Death in a circle | Execution in Circle

int solve(vector<int> &v, int idx, int k) {

	if (v.size() == 1) return v[0];

	idx = ( idx + k ) % v.size();
	v.erase(v.begin() + idx);
	solve(v, idx, k);

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr) ;
#endif

	int n, k;
	cin >> n >> k;
	k--;
	vector<int>v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	cout << solve(v, 0, k);

}
