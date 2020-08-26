/*

A node in a Doubly linked list has the following properties: data, prev and next. data
is the value for the linked list node, next and prev is a pointer to next and previous instance of 
ListNode

*/

function ListNode(data) {
  this.next = null;
  this.prev = null;
  this.data = data;
}

/*
  
  A linked list, in its simplest form, is a collection of nodes that together form a
  linear ordering.
  */

class DoublyLinkedList {
  constructor() {
    this.root = null;
    this.count = 0;
  }

  /* insert Node at the end */
  insert(data) {
    let temp = this.root;
    let newNode = new ListNode(data);

    if (this.root == null) {
      this.root = newNode;
      this.count++;
      return;
    }

    while (true) {
      if (temp.next == null) {
        newNode.prev = temp;
        temp.next = newNode;

        /*
        To make this Circular doubly linked listed add:

        newNode.next  = this.root;

        coz 1->2->3 is transformed to 3->1->2->3->1 and it is infinite traversal

        */

        this.count++;
        break;
      }
      temp = temp.next;
    }
  }

  /* insert Node at the front */

  insertFront(data) {
    let newNode = new ListNode(data); //data->null;
    newNode.next = this.root; // data->root;
    this.root.prev = newNode;
    this.root = newNode;
    this.count++;
  }

  /* Delete a node with a given value and return a bool response */
  delete(value) {
    let temp = this.root;
    if (temp == null) console.log("Empty");
    let prevNode = temp; // a node previous to the node to be deleted; eg) 4 in 4->5->6  while 5 to be deleted

    /* Delete first elemnt check */
    if (this.root.data == value) {
      console.log("A node deleted successfully!");
      this.root = this.root.next;
      this.root.prev = null; // 1->2->3;  if 1 is deleted root = 2 and  2->prev = null
      this.count--;
      return true;
    }

    /* 1->2->3 if 2 is deleted then 1 -> 3 and 1 <- 3  */
    while (temp != null) {
      if (temp.data == value) {
        console.log("A node deleted successfully!");
        prevNode.next = temp.next;
        temp.next.prev = prevNode;

        //delet the node
        delete temp.data;
        temp.next = null;
        temp.prev = null;

        this.count--;

        return true;
      }
      prevNode = temp;
      temp = temp.next;
    }
    console.log("A node is not found!");
    return false;
  }

  /* size of the DoublyLinkedList */
  size() {
    return this.count;
  }

  /* Traverse the linked list while printing data in forward and backward
  
  Forward: 1->2->3->4 
  Backward: 4<-3<-2<-1

  */
  print() {
    let temp = this.root;
    if (temp == null) console.log("Empty");
    while (temp.next != null) {
      console.log(temp.data);
      temp = temp.next;
    }
  }

  printReverse() {
    let temp = this.root;
    if (temp == null) console.log("Empty");

    while (temp.next != null) {
      temp = temp.next;
    }

    console.log(temp.data);

    while (temp != null) {
      console.log(temp.data);
      temp = temp.prev;
    }
  }
}

let ll = new DoublyLinkedList();
ll.insert(1);
ll.insert(2);
ll.insert(3);
ll.insert(4);
ll.insert(5);
ll.insert(6);
ll.insert(7);
ll.insert(8);

ll.insertFront(0);
ll.delete(0);
ll.delete(4);
ll.print();
