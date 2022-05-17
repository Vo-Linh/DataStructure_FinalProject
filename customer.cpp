#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.cpp"
#include <iostream>
// ======================================================================
// *                      Define Structure Customer                     *
// ======================================================================

using namespace std;
 
 struct customers
{
    int id;
    char name[20];
    char add[20];
    char product[100];
    int money;
};
typedef struct customers CUSTOMERS;

struct node {
    CUSTOMERS data;
    struct node* left;
    struct node* right;
};
 
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
    if (node == NULL)
        return;
 
    storeInorder(node->left, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    storeInorder(node->right, inorder, index_ptr);
}
 
int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
 
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;
 
    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);
 
    /* Now update root's data and increment index */
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}
 
// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;
 
    int n = countNodes(root);
 
    int* arr = new int[n];
    int i = 0;
    storeInorder(root, arr, &i);
 
    qsort(arr, n, sizeof(arr[0]), compare);
 
    i = 0;
    arrayToBST(arr, root, &i);
    delete[] arr;
}
 
struct node* newNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 

    printInorder(node->left);

    cout <<" "<< node->data;
 
    printInorder(node->right);
}
