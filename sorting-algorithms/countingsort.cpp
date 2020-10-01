#include <bits/stdc++.h>

using namespace std;

void countingsort(vector<int> &v, int n) {
    int largest_element_of_vector = *max_element(v.begin(), v.end());

    vector<int> hash(largest_element_of_vector + 1, 0);

    for(int i = 0;i < n;i++) {
        hash[v[i]]++;
    }

    int idx = 0;
    for(int i = 0;i <= largest_element_of_vector;i++) {
        while(hash[i] > 0) {
            v[idx] = i;
            hash[i]--;
            idx++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }
    
    countingsort(v, n);

    for(int i = 0;i < n;i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}