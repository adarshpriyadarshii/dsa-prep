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
    
node* lowestCommonAncestor(node* root, node* p, node* q) {
        if(!root) return NULL;
        int curr = root->data; 
        if(curr < p->data && curr < q->data) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->data && curr > q->data) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
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

  node* sol=lowestCommonAncestor(root,root->left->left, root -> left -> right -> left);
  int ans=sol->data;
  cout<<"The Lowest Common Ancestor is: "<<ans<<endl;
  return 0;
}