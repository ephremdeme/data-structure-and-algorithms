#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

//Kth symbol in grammer [observation skills]
//LeetCode

// Grammer ->
// if n=1 & k=1 [0]
// 0 -> 01
// 1 -> 10

// -----> k=1 to so on
// n=1 0
// n=2 0 1
// n=3 0 1 1 0
// n=4 0 1 1 0 1 0 1 0

// at each level total elements becomes twice and total ele at each level are 2^(n-1)

//Output 0/1 bit at n,k location

int solve(int n, int k) {

	int mid = pow(2, n - 1) / 2;

	if (n == 1 && k == 1) {
		return 0;
	}

	if (k <= mid) return solve(n - 1, k);
	else return !solve(n - 1, k - mid);
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	cout << solve(n, k) << endl;

}

