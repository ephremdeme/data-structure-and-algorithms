#include <iostream>
#include <map>
using namespace std;

bool canBePalindrome(map<char, int> m) {
	int oddOccurrence = 0;
	for (auto itr = m.begin(); itr != m.end(); itr++) {
		if (itr->second % 2) oddOccurrence += 1;
		if (oddOccurrence > 1)  return false;
	}
	return true;
}

int main() {
	string input;
	cin >> input;
	map<char, int> occurrenceCount;
	for (char c: input) {
		occurrenceCount[c] += 1;
	}
	cout << canBePalindrome(occurrenceCount) << endl;
	return 0;
}
