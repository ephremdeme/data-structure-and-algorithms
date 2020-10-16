#include<bits/stdc++.h>
using namespace std;

// Maximum area of rectangle in a binary matrix
int MAH(vector<int> a, int n) {
	vector<int> left;
	vector<int> right;
	stack<pair<int, int>> s;
	stack<pair<int, int>> s1;

// NSL
	for (int i = 0; i < n; i++) {

		if (s.size() == 0) left.push_back(-1);
		else if (s.size() > 0 && s.top().first < a[i]) {
			left.push_back(s.top().second);
		}
		else if (s.size() > 0 && s.top().first >= a[i]) {
			while (s.size() > 0 && s.top().first >= a[i]) {
				s.pop();
			}
			if (s.size() == 0) left.push_back(-1);
			else left.push_back(s.top().second);
		}
		s.push({a[i], i});
	}
//NSR
	for (int i = n - 1; i >= 0; i--) {

		if (s1.size() == 0) right.push_back(n);
		else if (s1.size() > 0 && s1.top().first < a[i]) {
			right.push_back(s1.top().second);
		}
		else if (s1.size() > 0 && s1.top().first >= a[i]) {
			while (s1.size() > 0 && s1.top().first >= a[i]) {
				s1.pop();
			}
			if (s1.size() == 0) right.push_back(n);
			else right.push_back(s1.top().second);
		}
		s1.push({a[i], i});
	}
	reverse(right.begin(), right.end());

	int area = INT_MIN;
	int temp;
	for (int i = 0; i < n; i++) {
		temp = (right[i] - left[i] - 1) * a[i];
		area = max(area, temp);
	}
	return area;
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n][n];

	vector<int> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int j = 0; j < n; j++) {
		v.push_back(a[0][j]);
	}

	int ans = MAH(v, n);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) v[j] = 0;
			else v[j] = v[j] + a[i][j];
		}
		ans = max(ans, MAH(v, n));
	}

	cout << ans;

}
