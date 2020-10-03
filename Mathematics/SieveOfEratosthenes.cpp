#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
bool sieve[MAX];
void sieveOfEratosthenes() {
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for(int i = 2;i < MAX;i++) {
        if(sieve[i] == true) {
            for(int j = 2 * i;j < MAX;j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    sieveOfEratosthenes();

    if(sieve[n] == true) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }

    return 0;
}