#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

void Insert(vector<int>&v, int temp) {

	if (v.size() == 0 || v[v.size() - 1] <= temp) {
		v.push_back(temp);
		return;
	}

	int val = v[v.size() - 1];
	v.pop_back();
	Insert(v, temp);
	v.push_back(val);

	return;
}

void Sort(vector<int>&v) {

	if (v.size() == 1) return; //already sorted

	int temp = v[v.size() - 1];
	v.pop_back();
	Sort(v);
	Insert(v, temp);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> v = {1, 0, 5, 2};
	Sort(v);

	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}


