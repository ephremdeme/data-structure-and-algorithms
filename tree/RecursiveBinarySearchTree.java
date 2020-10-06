public class RecursiveBinarySearchTree {

	public static BinarySearchTree of(int... values) {
		BinarySearchTree t = new RecursiveBinarySearchTree();
		for (int value: values)
			t.insert(value);

		return t;
	}

	public static BinarySearchTree createEmpty() {
		return new RecursiveBinarySearchTree();
	}

	public boolean isEmpty() {
		return root == null;
	}

	public void insert(int value) {
		if (root != null)
			recursiveInsert(root, value);
		else
			root = new Node(value);
	}

	public int getValueAtRoot() {
		return root.value;
	}

	public boolean isPresent(int value) {
		return findNode(value) != null;
	}

	public boolean remove(int value) {
		ChildAndParentNode nodeToRemoveWithParent = findNodeWithParent(value);
		
		if (nodeToRemoveWithParent == null)
			return false;
		
		Node nodeToRemove = nodeToRemoveWithParent.child;
		Node nodeToRemoveParent = nodeToRemoveWithParent.parent;

		return remove(nodeToRemove, nodeToRemoveParent);
	}

	private boolean remove(Node nodeToRemove, Node nodeToRemoveParent) {
		if (nodeToRemove.isLeaf()) 
			removeLeaf(nodeToRemoveParent, nodeToRemove);
		else if (nodeToRemove.hasASingleChild())
			removeNodeWithSingleChild(nodeToRemoveParent, nodeToRemove);
		else
			removeNodeWithTwoChildren(nodeToRemoveParent, nodeToRemove);

		return true;
	}

	private void removeLeaf(Node parent, Node leaf) {
		replaceNode(parent, leaf, null);
	}
	
	private void removeNodeWithSingleChild(Node parent, Node node) {
		Node nodeToRemoveChild = findSingleChild(node);

		replaceNode(parent, node, nodeToRemoveChild);
	}

	private void removeNodeWithTwoChildren(Node parent, Node node) {
		Node rightSubTree = node.right;

		ChildAndParentNode leftmostOfRightSubTreeWithParent 
			= rightSubTree.getLeftmostWithParent(node);
		
		Node leftmostOfRightSubTree = leftmostOfRightSubTreeWithParent.child;
		Node leftmostOfRightSubTreeParent = leftmostOfRightSubTreeWithParent.parent;

		replaceNode(leftmostOfRightSubTreeParent, leftmostOfRightSubTree, leftmostOfRightSubTree.right);

		leftmostOfRightSubTree.left = node.left;
		leftmostOfRightSubTree.right = node.right;

		replaceNode(parent, node, leftmostOfRightSubTree);
	}
	
	private Node findSingleChild(Node node) {
		Node child;
		if (node.left != null) 
			child = node.left;
		else 
			child = node.right;
		
		return child;
	}

	private void replaceNode(Node parent, Node toReplace, Node replacingNode) {
		if (parent == null) 
			root = replacingNode;
		else if (parent.left == toReplace) 
			parent.left = replacingNode;
		else 
			parent.right = replacingNode;
	}
	
	private Node recursiveInsert(Node node, int value) {
		if (node != null) {
			if (value >= node.value) {
				node.right = recursiveInsert(node.right, value);
			} else {
				node.left = recursiveInsert(node.left, value);
			}
			
			return node;
		} else {
			return new Node(value);
		}
	}
	
	private Node findNode(int value) {
		ChildAndParentNode childAndParent = findNodeWithParent(value);

		if (childAndParent == null)
			return null;

		return childAndParent.child;
	}

	private ChildAndParentNode findNodeWithParent(int value) {
		return findNodeWithParent(new ChildAndParentNode(root, null), value);
	}

	private ChildAndParentNode findNodeWithParent(ChildAndParentNode childAndParent, int value) {
		if (childAndParent.child == null)
			return null;
		else if (value == childAndParent.child.value)
			return childAndParent;
		else
			return findNodeWithParent(
				new ChildAndParentNode(getCorrectSubtree(childAndParent.child, value), childAndParent.child),
				value
			);
		
	}

	private Node getCorrectSubtree(Node node, int value) {
		if (value > node.value)
			return node.right;
		else
			return node.left;
	}


	private Node root;

	private class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int value) {
			this.value = value;
		}

		public boolean isLeaf() {
			return left == null && right == null;
		}

		public int getNumberOfChildren() {
			Node[] children = getChildren();

			int count = 0;
			for (Node child : children)
				if (child != null)
					count++;

			return count;
		}

		public boolean hasASingleChild() {
			return getNumberOfChildren() == 1;
		}
		
		public ChildAndParentNode getLeftmostWithParent(Node parent) {
			if (this.left == null)
				return new ChildAndParentNode(this, parent);

			return this.left.getLeftmostWithParent(this);
		}

		private Node[] getChildren() {
			return new Node[] {left, right};
		}
	}

	private class ChildAndParentNode {
		public Node child;
		public Node parent;

		public ChildAndParentNode(Node child, Node parent) {
			this.child = child;
			this.parent = parent;
		}

		public boolean isOrphan() {
			return parent == null;
		}
	}
}
