#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

vector<int> v;
stack<int> s;

// Nearest Smaller to Right - NSR
void solve(int a[], int n) {

	for (int i = n - 1; i >= 0 ; i--) {

		if (s.size() == 0) {
			v.push_back(-1);
		}

		else if (s.size() > 0 && s.top() < a[i]) {
			v.push_back(s.top());
		}
		else if (s.size() > 0 && s.top() >= a[i]) {
			while (s.size() > 0 && s.top() >= a[i]) {
				s.pop();
			}

			if (s.size() == 0) v.push_back(-1);
			else v.push_back(s.top());
		}

		s.push(a[i]);

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

	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) cout << v[i] << " ";

}

