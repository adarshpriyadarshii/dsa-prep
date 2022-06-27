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

int findCeil(node *root, int key){

	int ceil = -1; 
    while (root) {

        if (root->data == key) {
            ceil = root->data;
            return ceil;
        }
 
        if (key > root->data) {
            root = root->right;
        }
        else {
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; 
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  //root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);
 
 int ans=findCeil(root,6);
 cout<<ans;
  return 0;
}