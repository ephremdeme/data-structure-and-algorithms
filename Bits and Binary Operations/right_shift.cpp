#include <iostream>
#include <bits/stdc++.h>
using std::vector;
using namespace std;

//takes a cpp vector of ones and zeroes and performs a right shift on it

vector<int> rightShift(vector<int> number)
{
    vector<int> new_Number = number;
    for (int i = 0; i < number.size() - 1; i++)
    {
        new_Number[i + 1] = number[i];
    }
    new_Number[0] = 0;
    return new_Number;
}

int main(void)
{
    vector<int> binary_number = {1, 0, 1, 0, 0, 0, 1};
    vector<int> right_shifted_number = rightShift(binary_number);
    for (int i = 0; i < right_shifted_number.size(); i++)
    {
        cout << right_shifted_number[i];
    }
}