#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    
    int hash1[26], hash2[26];
    memset(hash1, 0, sizeof(hash1));
    memset(hash2, 0, sizeof(hash2));

    for(char c : s) {
        hash1[c - 'a']++;
    }

    for(char c : t) {
        hash2[c - 'a']++;
    }

    bool flag = true;
    for(int i = 0;i < 26;i++) {
        if(hash1[i] != hash2[i]) {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
