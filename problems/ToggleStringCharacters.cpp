#include<bits/stdc++.h> 
using namespace std; 

int main()
{
    int i;
    char str[101];
    cin >> str;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else
        {
            str[i] = str[i];
        }
    }
    cout << str << endl;
    return 0;
}