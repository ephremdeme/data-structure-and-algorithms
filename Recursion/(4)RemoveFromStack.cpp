#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define endl "\n"

//Remove mid position element from stack

stack<int> Remove(stack<int>&s, int mid) {

	if (mid == 1) { //nothing to remove
		s.pop();
		return s;
	}
	int temp = s.top();
	s.pop();
	Remove(s, mid - 1);
	s.push(temp);

	return s;
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


	int mid = s.size() / 2 + 1;

	Remove(s, mid);

	while (!s.empty()) { cout << s.top() << " "; s.pop(); }
	cout << endl;
}


