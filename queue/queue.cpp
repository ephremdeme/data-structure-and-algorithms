#include <cstring>
#include <iostream>

using namespace std;

template <class T>

/* Designing the queue ADT interfaces by using templates for generic programming
    which means the queue accepts any data type. */

class Queue
{

private:
    T* arr;  //the array to store data;
    int siz; //size of the array
    int t;  // positional index to the first of the array.
public:
    Queue(int queueSize = 20);
    int size() ;  //Return size
    bool empty(); // Check it is empty
    T& front(); //return front of the queue element;
    T& rear(); // return rear element of the queue
    void enqueue(const T& elem); // enqueue an element to the queue
    T& dequeue(); //return first of the queue and remove the element;

};

template <class T> Queue<T>::Queue(int queueSize)
{
    siz = queueSize;
    arr = new T[queueSize];
    t = -1;
}

template <class T> int Queue<T>::size()
{
    return t+1;
}

template <class T> bool Queue<T>::empty()
{
    if(t<0)
    {
        cout<<"Empty queue"<<endl;
        return true;
    }
    return false;
}

template <class T>  T& Queue<T>::front()
{
    if(empty())
        cout<<"Empty"<<endl;

    return arr[0];
}

template <class T>  T& Queue<T>::rear()
{
    if(empty())
        cout<<"Empty"<<endl;

    return arr[t];
}

template <class T>  T& Queue<T>::dequeue()
{
    if(empty())
        cout<<"queue Underflow"<<endl;


    // To hold the value of first element from arr to temp;
    T* tmp = new T[1];
    tmp[0] = arr[0];

    /* To shift an array to one place in the right which means
        arr = [1, 2, 3, 4] is shifted to
        arr = [2, 3, 4]
        */
    for(int i=0; i<t; i++){
        arr[i] = arr[i+1];
    }
    t--;
    return tmp[0];
}

template <class T> void Queue<T>::enqueue(const T& elem)
{
    if(t<=siz)
        arr[++t] = elem;
    else
        cout<<"queue Overflow"<<endl;
}


int main()
{
    Queue<int> st(10);
    st.enqueue(1);
    cout<<st.front()<<"\t";
    st.enqueue(2);
    cout<<st.front()<<"\t";
    st.enqueue(3);
    cout<<st.rear()<<endl;
    cout<<st.dequeue()<<"\t";
    cout<<st.front()<<" \t";
    cout<<st.rear();


    cout<<st.dequeue();

    return 0;
}
