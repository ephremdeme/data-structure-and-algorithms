
//Travelling Salesman Problem
//Minimum weight hamiltonian cycle (set of edges such that every node is visited)
//Travel all vertices and return to source

//if no direct edge between cities then weight=INT_MAX

//Brute force O(n)!   all permutations of vertices
//We will use DP

//Use bitmask to store set of visited cities so far in current branch

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int n = 4;

int dp[16][4]; //dp[1<<n][n]

int dist[10][10] = { //Adj Matrix
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

int visited_all = (1 << n) - 1;


int tsp(int mask, int pos) { //O(n-1)!

	if (mask == visited_all) {
		return dist[pos][0];
	}

	int ans = INT_MAX;

//Try to go to an unvisited city
	for (int city = 0; city < n; city++) {

		if ((mask & (1 << city)) == 0) {

			int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, newAns);

		}
	}
	return ans;
}

int tsp_topdown(int mask, int pos) { //O((2^n)*n)

	if (mask == visited_all) {
		return dist[pos][0];
	}


	if (dp[mask][pos] != -1) return dp[mask][pos];

	int ans = INT_MAX;

//Try to go to an unvisited city
	for (int city = 0; city < n; city++) {

		if ((mask & (1 << city)) == 0) {

			int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, newAns);

		}
	}
	return dp[mask][pos] = ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	memset(dp, -1, sizeof(dp));

	cout << tsp(1, 0) << endl;
	cout << tsp_topdown(1, 0) << endl;

}

