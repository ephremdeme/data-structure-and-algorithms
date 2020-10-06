#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
Node *newNode(int data) 
{ 
    Node *new_node = new Node; 
    new_node->data = data; 
    new_node->left = new_node->right = NULL; 
    return new_node; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void inorder(Node * node) 
{ 
    if (!node) 
        return; 

    inorder(node->left); 
    printf("%d ", node->data); 
    inorder(node->right);
     
} 
  
/* Function to merge given two binary trees*/
Node *MergeTrees(Node * t1, Node * t2) 
{ 
    if (!t1) 
        return t2; 
    if (!t2) 
        return t1; 
    t1->data += t2->data; 
    t1->left = MergeTrees(t1->left, t2->left); 
    t1->right = MergeTrees(t1->right, t2->right); 
    return t1; 
} 
  
// Driver code 
int main() 
{ 

    Node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
    root1->right->right = newNode(6); 

    Node *root2 = newNode(4); 
    root2->left = newNode(1); 
    root2->right = newNode(7); 
    root2->left->left = newNode(3); 
    root2->right->left = newNode(2); 
    root2->right->right = newNode(6); 
  
    Node *root3 = MergeTrees(root1, root2); 
    printf("The Merged Binary Tree is:\n"); 
    inorder(root3); 
    return 0; 
} 