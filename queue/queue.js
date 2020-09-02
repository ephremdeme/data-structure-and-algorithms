/* 

A queue is a container of elements that are inserted and removed according
to the first-in first-out (FIFO) principle. Elements can be inserted in a queue at any
time, but only the element that has been in the queue the longest can be removed at
any time.

*/

class Queue {
  constructor() {
    this._array = [];
  }

  /* inserts element to the back of a queue and catch args */
  enqueue(x, ...args) {
    this._array.push(x);
    args.map((elem) => this._array.push(elem));
  }

  /* return front element in the queue 
      and removes it from the queue 
      Underflow if queue is empty  */
  dequeue() {
    if (this.isEmpty()) return "Underflow";
    return this._array.shift();
  }

  /* returns front element without deleting it*/
  peek() {
    if (this.isEmpty()) return "Empty";
    return this._array[0];
  }

  /* returns the rear element */
  rear() {
    if (this.isEmpty()) return "Empty";
    return this._array[this.size() - 1];
  }

  isEmpty() {
    return this._array.length == 0;
  }

  /* returns size of the queue */
  size() {
    return this._array.length;
  }

  toString() {
    return this._array.toString();
  }

  printQueue() {
    let str = "";
    this._array.map((elem) => {
      str += elem + ", ";
    });
    return str.substring(0, str.length - 2);
  }
}

let st = new Queue();
st.enqueue(1);
st.enqueue(2, 3, 4, 5);
st.printQueue();
console.log(st.dequeue());
console.log(st.isEmpty(), st.peek(), st.dequeue(), st.enqueue(6), st.dequeue());
