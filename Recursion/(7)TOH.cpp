#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

void TOH(int n, char S, char D, char H) {

	if (n == 1) {
		cout << "Move disk " << n << " from " << S << " to " << D << endl;
		return;
	}

	TOH(n - 1, S, H, D);
	cout << "Move disk " << n << " from " << S << " to " << D << endl;
	TOH(n - 1, H, D, S);

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

	TOH(n, 'S', 'D', 'H');

}



