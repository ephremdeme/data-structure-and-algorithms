public class CircularLinkedListByRishinPandit{
    public class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }

    public Node head = null;
    public Node tail = null;

    public void add(int data){
        Node newNode = new Node(data);

        if(head == null){
            head = newNode;
            tail = newNode;
            newNode.next = head;
        }
        else {
            tail.next = newNode;
            tail = newNode;
            tail.next = head;

        }
    }

    public void display(){
        Node current = head;
        if(head == null){
            System.out.println("List is empty");
        }
        else{
            System.out.println("Nodes of the circular linked list: ");
            do{
                System.out.print(" "+ current.data);
                current = current.next;
            }while(current != head);
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        CircularLinkedListByRishinPandit c1 = new CircularLinkedListByRishinPandit();
        c1.add(10);
        c1.add(20);
        c1.add(30);
        c1.add(40);

        c1.display();
    }
}