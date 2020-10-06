#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define endl "\n"

// Print N-bit binary numbers having more/equal 1’s than 0’s for any prefix

void solve(string op, int n, int ones, int zeroes) {

	if (n == 0) {
		cout << op << " ";
		return;
	}

	solve(op + '1', n - 1, ones + 1, zeroes);
	if (ones > zeroes) {
		solve(op + '0', n - 1, ones, zeroes + 1);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string op = "";
	int ones = 0, zeroes = 0;

	solve(op, n, ones, zeroes);
}
