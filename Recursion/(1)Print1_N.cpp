#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"


void Print1_N(int n) {

	if (n == 1) {
		cout << n << " ";
		return;
	}
	Print1_N(n - 1);
	cout << n << " ";
}

void PrintN_1(int n) {

	if (n == 1) {
		cout << n << " ";
		return;
	}
	cout << n << " ";
	PrintN_1(n - 1);
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
	Print1_N(n);
	cout << endl;
	PrintN_1(n);

}


