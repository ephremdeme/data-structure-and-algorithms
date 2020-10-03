#include <bits/stdc++.h>
using namespace std;

int fib(int *arr, int n)
{
  if (n == 0 || n == 1)
    return 1;

  if (arr[n] > 0)
    return arr[n];

  int output = fib(arr, n - 1) + fib(arr, n - 2);
  arr[n] = output;
  return output;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int *input = new int[n];
  for (int i = 0; i < n; i++)
    input[i] = 0;

  cout << fib(input, n);
  delete[] input;
}