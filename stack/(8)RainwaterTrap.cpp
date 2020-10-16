#include<bits/stdc++.h>
using namespace std;

// Rainwater trapping (total trapped water)

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int maxL[n];
	int maxR[n];

	maxL[0] = a[0];
	maxR[n - 1] = a[n - 1];

	for (int i = 1; i < n; i++) {
		maxL[i] = max(maxL[i - 1], a[i]);
	}

	for (int i = n - 2; i >= 0; i--) {
		maxR[i] = max(maxR[i + 1], a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ans + min(maxL[i], maxR[i]) - a[i];
	}

	cout << ans << endl;

}
