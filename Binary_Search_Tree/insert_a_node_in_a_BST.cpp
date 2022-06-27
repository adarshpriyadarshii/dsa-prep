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

node* insertIntoBST(node* root, int val) {
        if(root == NULL) return newNode(val);
        node *cur = root;
        while(true) {
            if(cur->data <= val) {
                if(cur->right != NULL) cur = cur->right;
                else {
                    cur->right = newNode(val);
                    break;
                }
            } else {
                if(cur->left != NULL) cur = cur->left;
                else {
                    cur->left = newNode(val);
                    break;
                }
            }
        }
        return root;
    }

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if(curr == NULL) return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

int main() {

  struct node * root = newNode(4);
  root->left=newNode(2);
  root->left->left=newNode(1);
  root->left->right=newNode(3);
  root->right=newNode(7);
  
  node* root1=insertIntoBST(root,5);

  vector < int > inOrder;
  inOrderTrav(root1, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
 
  return 0;
}