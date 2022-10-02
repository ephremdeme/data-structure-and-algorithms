#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
//  ||          ||  || || || ||  || || || ||  || || || || ||
//  || ||    || ||  ||           ||                 ||
//  ||    ||    ||  || || ||     || || ||           ||
//  ||          ||  ||           ||                 ||
//  ||          ||  || || || ||  || || || ||        ||
void setIO(){
    fast:
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int n=5;
vector <int> Fib(n,-1);
int fibonaci(int n){
   if(n==0){
       Fib[n]=0;
       return 0;
   }
   else if(n==1){
       Fib[1]=1;
       return 1;
   }
   else if(Fib[n]==-1){
    //    fibonaci(n-1);
    //    fibonaci(n-2);
       Fib[n]=fibonaci(n-1)+fibonaci(n-2);
    //    cout<<Fib[n]<<endl;

    //    return;
   }
   return Fib[n];
}
void solve() {
  fibonaci(n-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // setIO();

    int tc = 1;
    // cin >> tc;
        solve();
    for (int t = 0; t < n; t++) {
        cout<<Fib[t]<<" ";
    }
    cout<<endl;
}