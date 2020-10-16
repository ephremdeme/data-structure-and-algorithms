#include<bits/stdc++.h>
using namespace std;

// Min stack implementation without using ss stack i.e. in O(1) space

stack<int> s;
int minEle;

void push(int a) {

	if (s.size() == 0)  { s.push(a); minEle = a; }

	else {

		if (a >= minEle) {
			s.push(a);
		}
		else {
			s.push(2 * a - minEle);
			minEle = a;
		}

	}
	return;
}

int pop() {
	int ans;
	if (s.size() == 0) return -1;

	else {
		if (s.top() >= minEle) {
			ans = s.top();
			s.pop();
		}
		else {
			minEle = 2 * minEle - s.top();
			ans = s.top();
			s.pop();
		}
	}

	return ans;
}

int top() {

	if (s.size() == 0) return -1;

	else {
		if (s.top() <= minEle) return minEle;
		else return s.top();
	}
}

int getMIN() {

	return s.size() == 0 ? -1 : minEle;
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
