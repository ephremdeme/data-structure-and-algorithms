#include <iostream>

using namespace std;

int queue[100], size, front, rear;

void enqueue(int);
void display();
void dequeue();

int main(){
    int choice, element;
    front = 0, rear = 0;
    cout << "Enter size of the queue:";
    cout << "\n";
    cin >> size;
    cout << "Enter your choice: \n 0.Exit \n 1.Enqueue \n 2.Dequeue \n 3.Display\n\n";
    cin >> choice;
  
    while(choice != 0) {
        switch(choice) {
            case 0:
            exit(0);
            
            case 1:
            if(rear == size){
                cout << "Queue overflow :(\n";
                exit(0);
            }
            cout << "Enter the element you want to add to the queue\n";
            cin >> element;
            enqueue(element);
            break;
            
            case 2:
            if(rear == front)
            {
                cout << "Queue underflow :|";
                exit(0);
            }
            dequeue();
            break;
            
            case 3:
            display();
            break;
        }
        
         cout << "\n Enter your choice: \n0.Exit \n1.Enqueue\n2.Dequeue\n3.Display\n\n";
         cin >> choice;
    }
}

void enqueue(int element){
    int i,j;
    i = 0;
    while(queue[i]!=0)
    {
        i++;
    }
    queue[i] = element;
    rear = i + 1;
}

void dequeue(){
    front++;
}

void display(){
    cout << "\nElements are:\n";
    for(int i = front; i < rear; i++){
        cout << queue[i] << "  ";
    }
}


