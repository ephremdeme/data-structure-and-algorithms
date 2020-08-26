#include <iostream>

using namespace std;


/*

A node in a singly linked list has the following properties: data and next. data
is the value for the linked list node, and next is a pointer to another instance of 
ListNode

*/


template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
};

/*

A linked list, in its simplest form, is a collection of nodes that together form a
linear ordering.
*/

template <class T>
class LinkedList
{

private:
    /*
        This can be referred as Root or Head of the Nodes
    */
    Node<T>* root;

public:

    LinkedList();
    ~LinkedList();

    bool isEmpty();
    void addFront(const T& elem); // //add elem to the front of the linked list
    void addBack(const T& elem); // add elem to the back of the Linked list;

    T& back(); //returns the end or back of the linked list node;
    T& front(); //returns the front of the linked list node;

    int removeBack(); // removes node from the back or at the end of the list;
    int removeFront(); // removes node from the front
    void print();
};


template <class T> LinkedList<T>::LinkedList()
{
    cout<<"Initialized"<<endl;
    root = NULL;
}

template <class T> LinkedList<T>::~LinkedList()
{
    while(!isEmpty())
    {
        removeFront();
    }
}

template <class T> T& LinkedList<T>::front()
{
    return root->data;
}

template <class T> T& LinkedList<T>::back()
{
    Node<T>* tmp = root;
    while(!tmp->next==NULL)
    {
        tmp = tmp->next;
    }

    return tmp->data;
}

template <class T> bool LinkedList<T>::isEmpty()
{
    return root==NULL;
}

template <class T> void LinkedList<T>::addFront(const T& elem)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = root;
    root = newNode;
}
template <class T> void LinkedList<T>::addBack(const T& elem)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = NULL;

    Node<T>* tmp = root;
    while(!tmp->next==NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}




/*
    Delete the front element and assign the rest to root
*/

template <class T> int LinkedList<T>::removeFront()
{
    if(isEmpty())
        return 0;
    Node<T>* old = root;
    root = old->next;
    delete old;
}

template <class T> int LinkedList<T>::removeBack()
{
    if(isEmpty())
        return 0;
    Node<T>* old = root;
    Node<T>* prev = NULL; //Used to set last element next to NULL;
    while(!old->next==NULL){
        prev = old;
        old= old->next;
    }
     prev->next = NULL;

    cout<<"Removed : " <<old->data<<endl;
    delete old;
}

/*
    print Linked list element while traversing the nodes
*/
template <class T> void LinkedList<T>::print()
{
    Node<T>* tmp = root;
    while(!tmp==NULL)
    {
        cout<<tmp->data<<"\t";
        tmp = tmp->next;
    }
    cout<<endl;
}

/*
int main()
{
    LinkedList<int> ll;
    ll.addFront(1);
    ll.addFront(2);
    ll.addFront(3);
    ll.addBack(0);
    ll.print();  //3 2 1 0
    ll.removeBack();
    ll.removeFront();
    ll.print(); // 2 1

    ll.addFront(3);
    ll.addBack(0);
    ll.print(); // 3 2 1

}

*/

