#include <iostream>
#include <bits/stdc++.h>
using std::vector;
using namespace std;

// takes in a c++ vector of ones and zeroes and returns a decimal equivalent
int binaryToDecimal(vector<int> number)
{
    int num = 0;
    reverse(number.begin(), number.end());
    for (int i = 0; i < number.size(); i++)
    {
        num += number[i] * pow(2, i);
    }
    return num;
}

int main(void)
{
    vector<int> binary_number = {1, 0, 1, 0, 0, 0, 1};
    int decimal_number = binaryToDecimal(binary_number);
    cout << decimal_number;
}