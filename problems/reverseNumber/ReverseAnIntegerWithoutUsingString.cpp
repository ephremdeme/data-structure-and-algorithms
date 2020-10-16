#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;

    while(n != 0) {
        result = result * 10 + (n % 10);
        n /= 10;
    }

    cout << result << endl;
    
    return 0;
}