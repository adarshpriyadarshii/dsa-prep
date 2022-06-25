#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};



int maxDepth(node* root,int& diameter){
    if(root==NULL)return 0;

    int lh=maxDepth(root->left,diameter);
    int rh=maxDepth(root->right,diameter);

    diameter=max(diameter,lh+rh);

    return 1+max(lh,rh);
}
int diameterOfBT(node* root){
    int diameter=0;
    int k=maxDepth(root,diameter);
    return k;
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

  int ans=diameterOfBT(root);
  cout<<ans<<endl;
  
  return 0;
}