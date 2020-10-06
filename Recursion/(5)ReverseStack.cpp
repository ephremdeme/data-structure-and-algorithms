#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

//Reverse stack in O(1) space
//We are only using rec call stack not any stack DS

void Insert(stack<int>&s, int temp) {

	if (s.size() == 0) {
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	Insert(s, temp);
	s.push(val);

	return;

}

void Reverse(stack<int>&s) {

	if (s.size() == 1) return ; //nothing to reverse

	int temp = s.top();
	s.pop();
	Reverse(s);
	Insert(s, temp);

}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(0);
	s.push(5);
	s.push(-1);
	s.push(10);

	Reverse(s);

	while (!s.empty()) { cout << s.top() << " "; s.pop(); }
	cout << endl;
}


