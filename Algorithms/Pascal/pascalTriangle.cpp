
#include <iostream>

using namespace std;

void printPascal(int n) {
    for (int line = 1; line <= n; line++) {
        // used to represent C(line, i)
        int C = 1;

        for (int i = 1; i < (n - line + 1); i++) {
            cout << " ";
        }

        for (int i = 1; i <= line; i++) {
            // The first value in a line is always 1
            cout << C << " ";
            C = C * (line - i) / i;
        }

        cout << "\n";
    }
}

// Execution
int main() {
    int n;

    cout << "Please provide the number of rows of the triangle: ";

    cin >> n;

    printPascal(n);
    
    return 0;
}
