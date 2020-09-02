class BinaryTree {
  constructor() {
    this.node = {
      left: null,
      right: null,
      data: null,
    };
  }

  print(root) {
    if (root == null) {
      return;
    }

    console.log(root.data);
    this.print(root.left);
    this.print(root.right);
  }

  insert(data, root) {
    if (root.data == null) {
      root.data = data;
      return;
    } else {
      if (data > root.data) {
        if (root.right == null) {
          let newNode = {
            left: null,
            right: null,
            data: data,
          };
          root.right = newNode;
          return root;
        } else this.insert(data, root.right);
      } else if (data < root.data) {
        if (root.left == null) {
          let newNode = {
            left: null,
            right: null,
            data: data,
          };
          root.left = newNode;
          return root;
        } else this.insert(data, root.left);
      }
    }
  }

  search(data, root) {
    if (data == root.data) {
      return data;
    }
    if (data < root.data) {
     return this.search(data, root.left);
    } else if (data > root.data) {
      return this.search(data, root.right);
    }else return null;
  }
}

let bst = new BinaryTree();
bst.insert(5, bst.node);
bst.insert(4, bst.node);
bst.insert(9, bst.node);
bst.insert(6, bst.node);
bst.insert(3, bst.node);
bst.insert(8, bst.node);
console.log(bst.node);
console.log(bst.search(8, bst.node));

// bt.print(bt.node);
