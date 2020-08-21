class Stack {
  constructor() {
    this.array = [];
  }

  push(x) {
    this.array.push(x);
  }

  /* return top most element in the stack 
    and removes it from the stack 
    Underflow if stack is empty  */
  pop() {
    if (this.isEmpity()) return "Underflow";
    return this.array.pop();
  }

  /* Used to get top most element without deleting it*/
  peek() {
    if (this.isEmpity()) return "Empity";
    return this.array[this.array.length - 1];
  }

  isEmpity() {
    return this.array.length == 0;
  }

  toString(){
      return this.array.toString()
  }

  printStack() {
    let str = "";
    this.array.map((elem) => {
      str += elem + ", ";
    });
    return str.substring(0, str.length-2);
  }
}

let st = new Stack();
st.push(1);
st.push(2);
st.printStack();
console.log(st.printStack());
