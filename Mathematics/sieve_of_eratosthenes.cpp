// CPP Code of Sieve Of Eratosthenes

#include <bits/stdc++.h>
using namespace std;

int *findPrime(int num) {

    int *prime = new int[num+1];

    prime[0] = 0, prime[1] = 0, prime[2] = 1;

    for(int i = 3; i <= num; ++i) {

        if(i%2) {

            prime[i] = 1;
        }
        else {

            prime[i] = 0;
        }
    }

    for(int i = 2; i <= num; ++i) {
        
        if(prime[i]) {
            
            for(int j = i*i; j <= num ; j += i) {

                prime[j] = 0;
            }
        }
    }

    return prime;
}

void showPrime(int *primeNum, int num) {

    for(int i = 0; i <= num; ++i) {
        
        if(primeNum[i]) {
            
            cout<<i<<" ";
        }
    }
}

int main() {

    int num;

    cin>>num;

    int *primeNum;

    primeNum = findPrime(num);

    showPrime(primeNum, num);

    return 0;
}