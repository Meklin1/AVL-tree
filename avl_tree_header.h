#ifndef AVL_TREE_HEADER_H_INCLUDED
#define AVL_TREE_HEADER_H_INCLUDED

typedef struct Node
{
    int data;
    struct Node *left,*right;
    int height;
}Node;

//function to check if value exists in the AVL tree
int checkValue (Node* node, int data);
//function to create new node
Node* newNode(int data);
//function to get the height of the subtree including the current node
int getHeight(Node *node);
//function to get the balance factor of subtrees
int getBalance(Node* node);
//function insert new value to the tree
Node* insert(Node* node, int data);
//function remove value from the tree
Node* deleteNode(Node* node, int data);
//function to print AVL tree values preorder
void printPreorder(Node* node);
//function to print AVL tree values in ascending order
void printInorder (Node* node);

#endif // AVL_TREE_HEADER_H_INCLUDED
