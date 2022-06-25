#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool f(node *root1, node* root2) {
        if(!root1) return !root2;
        if(!root2) return !root1;
        return (root1->data == root2->data) && f(root1->left, root2->right) && f(root1->right, root2->left);
    }
bool isSymmetric(node* root) {
        if(!root) return true;
        return f(root->left, root->right);
    }

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  bool symmetry=isSymmetric(root);
  
  cout<<(symmetry?"YES":"NO")<<endl;
  return 0;
}