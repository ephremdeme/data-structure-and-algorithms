class Stack {
  constructor() {
    //working
    this.stackarray = new Array();
  }
  push(value) {
    //if (index >= 10) throw 'Stack is full';
    this.stackarray.unshift(value);
  
  }
  pop() {
    index--;
    if (index < 0) {
      index = 0;
      throw 'Stack is empty';
    }
    return this.stackarray.shift();
    //return this.stackarray;
  }
}



let graphAdj;
let visited;
let stack;

//create an empty graph

const initGraph = (maxVertice) => {
       visited = new Array(maxVertice);
       stack = new Stack(); 
       queue = new Queue();for (let i = 0; i < visited.length; i++) {
         visited[i] = false;
      }graphAdj = new Array(maxVertice);for (let i = 0; i < graphAdj.length; i++) {
       graphAdj[i] = new Array(maxVert);
    }
   for (let i = 0; i < graphAdj.length; i++) {
        for (let j = 0; j < graphAdj[i].length; j++) {
           graphAdj[i][j] = 0;
        }
    }
  }

//insert values in empty graph with some kind of input method

const insertGraph = (a, b) => {
   for (let i = 0; i < graphAdj.length; i++) {
       for (let j = 0; j < graphAdj[i].length; j++) {
          if (i === a && j === b) {
             graphAdj[i][j] = 1;
             graphAdj[j][i] = 1;
          }
        }
    }
}

//pass in the start node
// eg.: dfs(graphAdj[0][0]);
const dfs = (node) => { 
     stack.push(node);
     while (stack.stackarray.length) {
        node = stack.pop();
        if (visited[node] == false) {
           visited[node] = true;
           console.log(`we visited ${node}`)
           for (let j = 0; j < graphAdj[node].length; j++) {
              if (graphAdj[node][j] === 1){
                  stack.push(j);
               }
            }
       }
     }
}
