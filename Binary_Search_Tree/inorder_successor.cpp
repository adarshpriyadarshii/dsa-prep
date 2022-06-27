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

int inorderSuccessor(node* root, node* p) {
        node* successor = NULL;
        
        while (root != NULL) {
            
            if (p->data >= root->data) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        return successor->data;
    }

int main() {

  struct node * root = newNode(4);
  root->left=newNode(2);
  root->left->left=newNode(1);
  root->left->right=newNode(3);
  root->right=newNode(7);
  
  int ans=inorderSuccessor(root,root->left->right);
  cout<<ans;
 
  return 0;
}