#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

// Letter case permutation
void LetterCasePerm(string ip, string op) {

	if (ip == "") {
		cout << op << endl;
		return;
	}

	if (isalpha(ip[0])) {
		char uc = toupper(ip[0]);
		char lc = tolower(ip[0]);
		LetterCasePerm(ip.substr(1), op + uc);
		LetterCasePerm(ip.substr(1), op + lc);
	}
	else {
		LetterCasePerm(ip.substr(1), op + ip[0]);
	}
}

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string ip; // ip will be of A1b2 kind
	cin >> ip;
	string op = "";

	LetterCasePerm(ip, op);

}

