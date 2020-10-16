#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

//Stock Span Problem
vector<int> v;
stack<pair<int, int>> s;

// Nearest Greater to Left - NGL
void solve(int a[], int n) {

	for (int i = 0; i < n; i++) {

		if (s.size() == 0) {
			v.push_back(-1);
		}

		else if (s.size() > 0 && s.top().first > a[i]) {
			v.push_back(s.top().second);
		}
		else if (s.size() > 0 && s.top().first <= a[i]) {
			while (s.size() > 0 && s.top().first <= a[i]) {
				s.pop();
			}

			if (s.size() == 0) v.push_back(-1);
			else v.push_back(s.top().second);
		}

		s.push({a[i], i});

	}

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
	int a[n];

	for (int i = 0; i < n; i++) cin >> a[i];
	solve(a, n);

	// reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) cout << i - v[i] << " ";

}

