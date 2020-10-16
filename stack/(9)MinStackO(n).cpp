#include<bits/stdc++.h>
using namespace std;

// Min stack implementation using ss stack

stack<int> s;
stack<int> ss; //supporting stack

void push(int a) {

	s.push(a);
	if (ss.size() == 0 || a <= ss.top()) {
		ss.push(a);
	}
	return;
}

int pop() {

	int val = s.top();
	s.pop();

	if (ss.top() == val) {
		ss.pop();
	}

	return val;
}

int getMIN() {

	return ss.size() == 0 ? -1 : ss.top();
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	push(18);
	push(19);
	push(29);
	push(15);
	pop();
	push(16);
	pop();
	pop();

	cout << getMIN() << endl;

}
