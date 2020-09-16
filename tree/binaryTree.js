class BinaryTree {
  constructor() {
    this._node = {
      left: null,
      right: null,
      data: null,
    };
  }

  insert(data) {
    insertHelper(data, this._node);
    function insertHelper(data, root) {
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
          } else insertHelper(data, root.right);
        } else if (data < root.data) {
          if (root.left == null) {
            let newNode = {
              left: null,
              right: null,
              data: data,
            };
            root.left = newNode;
            return root;
          } else insertHelper(data, root.left);
        }
      }
    }
  }

  /**
   * In-order traversal visits nodes in the following order: left, root (the current node),
   * right.
   */
  inOrderTraverse() {
    return inOrderTraverseHelper(this._node);
    function inOrderTraverseHelper(root) {
      if (root == null) return;
      inOrderTraverseHelper(root.left);
      console.log(root.data);
      inOrderTraverseHelper(root.right);
    }
  }

  /**
   * Pre-order traversal visits nodes in the following order: root (the current node), left.
   * right.
   */
  preOrderTraverse() {
    return preOrderTraverseHelper(this._node);
    function preOrderTraverseHelper(root) {
      if (root == null) return;

      console.log(root.data);
      this.print(root.left);
      this.print(root.right);
    }
  }

  /**
   * Post-order traversal visits nodes in the following order: left, right, 
   * root (the current node)
   * 
   */

  postOrderTraverse() {
    return postOrderTraverseHelper(this._node);
    function postOrderTraverseHelper(root) {
      if (root == null) return;
      this.print(root.left);
      this.print(root.right);
      console.log(root.data);
    }
  }

  /**
   * Searchs the BST for the given key
   * @param {int} data 
   */
  search(data) {
    return serachHelper(data, this._node);
    function serachHelper(data, root) {
      if (data == root.data) {
        return data;
      }
      if (data < root.data) {
        return serachHelper(data, root.left);
      } else if (data > root.data) {
        return serachHelper(data, root.right);
      } else return null;
    }
  }

  /**
   * Finds minimum element by traversing to left nodes until the last element
   */

  findMin() {
    return findMinRec(this._node);

    function findMinRec(root) {
      if (root.left == null) {
        return root.data;
      }
      return findMinRec(root.left);
    }
  }

  /**
   * Finds the maximum element by traversing to the right nodes.
   */
  findMax() {
    return findMaxRec(this._node);

    function findMaxRec(root) {
      if (root.left == null) {
        return root.data;
      }
      return findMaxRec(root.left);
    }
  }
}

let bst = new BinaryTree();
bst.insert(5);
bst.insert(4);
bst.insert(9);
bst.insert(6);
bst.insert(3);
bst.insert(8);
console.log(bst.search(8));
console.log(bst.findMin());
console.log(bst.findMax());
