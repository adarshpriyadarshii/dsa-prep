#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node* lowestCommonAncestor(node* root, node* p, node* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
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

  node* sol=lowestCommonAncestor(root,root->left->left, root -> left -> right -> left);
  int ans=sol->data;
  cout<<"The Lowest Common Ancestor is: "<<ans<<endl;

  return 0;
}