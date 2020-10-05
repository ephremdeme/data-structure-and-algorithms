#include <iostream>
using namespace std;

/*
bogosort just generates a random shuffle of the array until it finds a sorted shuffle.
time complexity: O(n!)
*/

bool is_not_sorted(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (i && arr[i-1] > arr[i]) {
			return true;
		}
	}
	return false;
}

void shuffle(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		swap(arr[i], arr[rand() % size]);
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void bogo_sort(int arr[], int size) {
	int i = 0;
	while (is_not_sorted(arr, size)) {
		shuffle(arr, size);
		i += 1;
	}
	cout << i << endl;
}

int main() {
	int test_size = 6;
	int test_arr[test_size] = {4, 5, 1, 3, 6, 2};
	bogo_sort(test_arr, test_size);
	for (int i: test_arr) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}