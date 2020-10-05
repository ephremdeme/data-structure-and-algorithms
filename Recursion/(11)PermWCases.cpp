#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

// Permutation with case change
void PermWithCases(string ip, string op) {

	if (ip == "") {
		cout << op << endl;
		return;
	}

	PermWithCases(ip.substr(1), op + ip[0]);
	char out = ip[0];
	out = toupper(out);
	PermWithCases(ip.substr(1), op + out);

}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string ip; // ip will be in lowercase alphabet
	cin >> ip;
	string op = "";

	PermWithCases(ip, op);

}

