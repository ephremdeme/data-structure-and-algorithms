#include <iostream>
#include <bits/stdc++.h>
using std::vector;
using namespace std;

//takes a cpp vector of ones and zeroes and performs a left shift on it
vector<int> leftShift(vector<int> number)
{
    vector<int> new_Number = number;
    for (int i = number.size() - 1; i > 0; i--)
    {
        new_Number[i - 1] = number[i];
    }
    new_Number[number.size() - 1] = 0;
    return new_Number;
}

int main(void)
{
    vector<int> binary_number = {1, 0, 1, 0, 0, 0, 1};
    vector<int> left_shifted_number = leftShift(binary_number);
    for (int i = 0; i < left_shifted_number.size(); i++)
    {
        cout << left_shifted_number[i];
    }
}