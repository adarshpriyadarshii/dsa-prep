#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
class Solution {
private: 
    node* first;
    node* prev;
    node* middle;
    node* last; 
private: 
    void inorder(node* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (prev != NULL && (root->data < prev->data))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(node* root) {
        first = middle = last = NULL; 
        prev = newNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->data, last->data); 
        else if(first && middle) swap(first->data, middle->data); 
    }
};
int main() {

  struct node * root = newNode(4);
  root->left=newNode(2);
  root->left->left=newNode(1);
  root->left->right=newNode(3);
  root->right=newNode(7);
  
  return 0;
}