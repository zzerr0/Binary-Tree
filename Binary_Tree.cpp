
#include <iostream>
using namespace std;

struct node {
  node *left, *right;
  int data;
};

node *newnode( int d ){
  node *NewNode = new node();
  NewNode->data = d;
  NewNode->left = NewNode->right = NULL;
  
  return NewNode ;
}

node *insert( int arr[], node *root, int i, int n){
  
  if( i < n){

  node *temp = newnode(arr[i]);
  root = temp;
  
  root->left = insert(arr, root->left, 2*i+1, n);
  root->right = insert( arr, root->right, 2*i+2, n);
  }
  
  return root;
}

void inOrder(node* root) 
{ 
    if (root != NULL) 
    { 
        inOrder(root->left); 
        cout << root->data <<" "; 
        inOrder(root->right); 
    } 
} 

int main()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    node* root = insert(arr, root, 0, n); 
    inOrder(root); 
}

