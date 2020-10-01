#include <bits/stdc++.h>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    //base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void reverseStack(stack<int> &s)
{
    //base case
    if (s.empty())
        return;

    //recursive case
    int x = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, x);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}

/*
Output
1 2 3 4 
*/