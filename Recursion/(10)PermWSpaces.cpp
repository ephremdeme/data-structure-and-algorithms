#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

// Permutation with spaces
void PermWithSpaces(string ip, string op) {

	if (ip == "") {
		cout << op << endl;
		return;
	}

	PermWithSpaces(ip.substr(1), op + ip[0]);
	PermWithSpaces(ip.substr(1), op + " " + ip[0]);

}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string ip;
	cin >> ip;
	string op = "";
	op = op + ip[0];
	PermWithSpaces(ip.substr(1), op);

}

