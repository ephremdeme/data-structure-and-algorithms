#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

//Print subsets / powersets / subsequences

void PrintSubseq(string ip, string op) {

	if (ip == "") { // i.e. we are at leaf node
		cout << op << endl;
		return;
	}

	PrintSubseq(ip.substr(1), op + ip[0]);
	PrintSubseq(ip.substr(1), op);

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

	PrintSubseq(ip, op);
}



