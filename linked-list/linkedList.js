/*

A node in a singly linked list has the following properties: data and next. data
is the value for the linked list node, and next is a pointer to another instance of 
ListNode

*/

function ListNode(data) {
  this.next = null;
  this.data = data;
}

/*

A linked list, in its simplest form, is a collection of nodes that together form a
linear ordering.
*/

class LinkedList {
  constructor() {
    this._root = null;
    this.count = 0;
  }

  /* insert Node at the end */
  insert(data) {
    let temp = this._root;
    if (this._root == null) {
      this._root = new ListNode(data);
      this.count++;
      return;
    }
    while (true) {
      if (temp.next == null) {
        temp.next = new ListNode(data);
        this.count++;
        break;
      }
      temp = temp.next;
    }
  }

  /* insert Node at the front */

  insertFront(data) {
    let newNode = new ListNode(data); //data->null;
    newNode.next = this._root; // data->root;
    this._root = newNode;
    this.count++;
  }

  /* Delete a node with a given value and return a bool response */
  delete(value) {
    let temp = this._root;
    if (temp == null) console.log("Empty");
    let prevNode = temp; // a node previous to the node to be deleted; eg) 4 in 4->5->6  while 5 to be deleted

    /* Delete first elemnt check */
    if (this._root.data == value) {
      console.log("A node deleted successfully!");
      this._root = this._root.next;
      this.count--;
      return true;
    }

    while (temp != null) {
      if (temp.data == value) {
        console.log("A node deleted successfully!");
        prevNode.next = temp.next;

        delete temp.data;
        temp.next = null;

        this.count--;

        return true;
      }
      prevNode = temp;
      temp = temp.next;
    }
    console.log("A node is not found!");
    return false;
  }

  /* size of the LinkedList */
  size() {
    return this.count;
  }

  /* Traverse the linked list while printing data */
  print() {
    let temp = this._root;
    if (temp == null) console.log("Empty");
    while (temp != null) {
      console.log(temp.data);
      temp = temp.next;
    }
  }
}

let ll = new LinkedList();
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
