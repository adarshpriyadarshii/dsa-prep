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
    
bool isValidBST(node* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (root->data >= maxVal || root->data <= minVal) return false;
        return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
    }

bool isValid(node* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  bool f=isValid(root);
  cout<<(f?"YES":"NO")<<endl;
  return 0;
}