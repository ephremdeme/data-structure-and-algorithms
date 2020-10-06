#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define endl "\n"

// Generate all balanced parenthesis
void solve(string op, int open, int close, vector<string> &v) {

	if (open == 0 && close == 0) {
		v.push_back(op);
		return;
	}

	if (open > 0) solve(op + '(', open - 1, close, v);
	if (close > open) solve(op + ')', open, close - 1, v);
	return;
}

void solve2(int n, string op, int open, int close, vector<string> &v) {

	if (open == n && close == n) {
		v.push_back(op);
		return;
	}

	if (open <= n) solve2(n, op + '(', open + 1, close, v);
	if (close < open) solve2(n, op + ')', open, close + 1, v);
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

	int close = n, open = n;
	string op = "";
	vector<string> v;
	solve(op, open, close, v);

	for (auto s : v) cout << s << " ";
	cout << endl;
	v.clear();

	op = "";
	open = 0;
	close = 0;
	solve2(n, op, open, close, v);

	for (auto s : v) cout << s << " ";
	cout << endl;

}
