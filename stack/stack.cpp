#include <iostream>

using namespace std;

template <class T>

/* Designing the Stack ADT interfaces by using templates for generic programming
    which means the stack accepts any data type. */

class Stack
{

private:
    T* arr;  //the array to store data;
    int siz; //size of the array
    int t;  // positional index to the top of the array.
public:
    Stack(int StackSize = 20);
    int size() ;  //Return size
    bool empty(); // Check it is empty
    T& top(); //return top of the stack element;
    void push(const T& elem); // push an element to the stack
    T& pop(); //return top of the stack and remove the element;

};

template <class T> Stack<T>::Stack(int StackSize)
{
    siz = StackSize;
    arr = new T[StackSize];
    t = -1;
}

template <class T> int Stack<T>::size()
{
    return t+1;
}

template <class T> bool Stack<T>::empty()
{
    if(t<0)
    {
        cout<<"Empty Stack"<<endl;
        return true;
    }
    return false;
}

template <class T>  T& Stack<T>::top()
{
    if(empty())
        cout<<"Empty"<<endl;

    return arr[t];
}

template <class T>  T& Stack<T>::pop()
{
    if(empty())
        cout<<"Stack Underflow"<<endl;

    return arr[t--];
}

template <class T> void Stack<T>::push(const T& elem)
{
    if(t<=siz)
        arr[++t] = elem;
    else
        cout<<"Stack Overflow"<<endl;
}


int main()
{
    Stack<int> st(10);
    st.push(1);
    cout<<st.top();
    cout<<st.pop();
    st.push(2);
    cout<<st.top();
    cout<<st.pop();
    st.push(3);
    cout<<st.top()<<endl;
    cout<<st.top()<<endl;
    cout<<st.pop()<<" " <<st.top()<<endl;

    return 0;
}
