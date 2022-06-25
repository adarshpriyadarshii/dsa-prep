#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};



int maxDepth(node* root){
    if(root==NULL)return 0;

    int lh=maxDepth(root->left);
    if(lh==-1) return -1;

    int rh=maxDepth(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);
}
bool isBalanced(node* root){
    int k=maxDepth(root);
    if(k==-1) return false;
    return true;
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
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  bool ans=isBalanced(root);
  cout<<ans<<endl;
  
  return 0;
}