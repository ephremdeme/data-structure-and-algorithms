#include <iostream>
#include <bits/stdc++.h>
using std::vector;
using namespace std;

//a program that takes a natural number and returns its binary equivalent in a vector
vector<int> decimalToBinary(int num)
{
    vector<int> number;
    if (num == 1)
    {
        number.push_back(num);
    }
    while (num != 1)
    {
        number.push_back(num % 2);
        num = num / 2;
        if (num == 1)
        {
            number.push_back(num);
        }
    }
    reverse(number.begin(), number.end());
    return number;
}

int main(void)
{
    int decimal_number = 81;
    vector<int> binary_number = decimalToBinary(decimal_number);
    for (int i = 0; i < binary_number.size(); i++)
    {
        cout << binary_number[i];
    }
}