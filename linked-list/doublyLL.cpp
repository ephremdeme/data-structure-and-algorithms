#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class DoublyLinkedList
{

private:
    /*
        This can be referred as Root or Head of the Nodes
    */
    Node<T>* header;
    Node<T>* tailer;

public:

    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty();
    void addFront(const T& elem); // //add elem to the front of the linked list
    void addBack(const T& elem); // add elem to the back of the Linked list;

    T& back(); //returns the end or back of the linked list node;
    T& front(); //returns the front of the linked list node;

    int removeBack(); // removes node from the back or at the end of the list;
    int removeFront(); // removes node from the front
    void print();
};


template <class T> DoublyLinkedList<T>::DoublyLinkedList()
{
    header = NULL;
    tailer = NULL;
}

template <class T> DoublyLinkedList<T>::~DoublyLinkedList()
{
    while(!isEmpty())
    {
        removeFront();
    }
    delete header;
    delete tailer;
}

template <class T> T& DoublyLinkedList<T>::front()
{
    return header->data;
}

template <class T> T& DoublyLinkedList<T>::back()
{
    Node<T>* tmp = header;
    while(!tmp->next==NULL)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <class T> bool DoublyLinkedList<T>::isEmpty()
{
    return header==NULL;
}

template <class T> void DoublyLinkedList<T>::addFront(const T& elem)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = header;
    newNode->prev = NULL;
    header = newNode;
}

template <class T> void DoublyLinkedList<T>::addBack(const T& elem)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = NULL;

    Node<T>* tmp = header;
    while(!tmp->next==NULL)
    {
        tmp = tmp->next;
    }

    newNode->prev = tmp;
    tmp->next = newNode;
}


/*
    Delete the front element and assign the rest to header
*/

template <class T> int DoublyLinkedList<T>::removeFront()
{
    if(isEmpty())
        return 0;
    Node<T>* old = header;
    header = old->next;
    delete old;
}

template <class T> int DoublyLinkedList<T>::removeBack()
{
    if(isEmpty())
        return 0;
    Node<T>* old = header;
    Node<T>* prev = NULL; //Used to set last element next to NULL;
    while(!old->next==NULL)
    {
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
template <class T> void DoublyLinkedList<T>::print()
{
    Node<T>* tmp = header;
    while(!tmp==NULL)
    {
        cout<<tmp->data<<"\t";
        tmp = tmp->next;
    }
    cout<<endl;
}


int main()
{
    DoublyLinkedList<int> ll;
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


