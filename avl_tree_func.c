#include <stdio.h>
#include <stdlib.h>
#include "avl_tree_header.h"

int checkValue (Node* node, int data)
{
    if(!node){
        return 0;
    }

    if(node->data == data){
        return 1;
    }

    if(node->data > data){
        checkValue(node->left, data);
    }
    else if(node->data < data){
        checkValue(node->right, data);
    }
}

Node* newNode(int data)
{
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->data = data;
    node->height = 1;
    return node;
}

int getHeight(Node *node)
{
    int leftHeight;
    int rightHeight;

    if(!node){
        return 0;
    }

    if(node->left == NULL){
        leftHeight = 1;
    }

    else{
        leftHeight = 1 + node->left->height;
    }

    if(node->right == NULL){
        rightHeight = 1;
    }

    else{
        rightHeight = 1 + node->right->height;
    }

    if(leftHeight > rightHeight){
        return leftHeight;
    }

    else{
        return rightHeight;
    }
}

Node* rotateLeft (Node* node)
{
    Node* root = node->right;

    node->right = root->left;
    root->left = node;
    node->height = getHeight(node);
    root->height = getHeight(root);

    return root;
}

Node* rotateRight (Node* node)
{
    Node* root = node->left;

    node->left = root->right;
    root->right = node;
    node->height = getHeight(node);;
    root->height = getHeight(root);

    return root;
}

int getBalance(Node* node)
{
    int leftHeight;
    int rightHeight;

    if(!node){
        return 0;
    }

    if(node->left == NULL){
        leftHeight = 1;
    }

    else{
        leftHeight = 1 + node->left->height;
    }

    if(node->right == NULL){
        rightHeight = 1;
    }

    else{
        rightHeight = 1 + node->right->height;
    }

    return leftHeight - rightHeight;
}
Node* balance (Node* node)
{
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0){
        return rotateRight(node);
    }

    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0){
        return rotateLeft(node);
    }

    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* insert(Node* node, int data)
{
    if (!node){
        return newNode(data);
    }

    if (node->data > data){
        node->left  = insert(node->left, data);
    }

    else if (data > node->data){
        node->right = insert(node->right, data);
    }

    else if (data == node->data){
        return node;
    }

    node->height = getHeight(node);

    return balance(node);
}

Node* deleteNode(Node* node, int data)
{
    if(!node){
        return NULL;
    }

    if (node->data > data){
        node->left  = deleteNode(node->left, data);
    }

    else if (node->data < data){
        node->right = deleteNode(node->right, data);
    }

    else if(node->data == data){
        if((node->left == NULL) || (node->right == NULL))
        {
            Node *temp = node->left ? node->left :  node->right;

            if (temp == NULL){
                free(node);
                node = NULL;
            }
            else{
                *node = *temp;
                free(temp);
            }
        }
        else
        {
            Node* temp = node->right;
            while (temp->left != NULL){
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == NULL){
        return node;
    }

    node->height = getHeight(node);
    return balance(node);
}

void printPreorder(Node* node)
{
    if(node != NULL)
    {
        printf("%d ", node->data);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void printInorder (Node* node)
{
    if(node == NULL){
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
