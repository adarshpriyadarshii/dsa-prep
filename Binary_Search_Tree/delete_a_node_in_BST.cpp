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
node* findLastRight(node* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }

node* helper(node* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            node* rightChild = root->right;
            node* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }

node* deleteNode(node* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == key) {
            return helper(root);
        }
        node *dummy = root;
        while (root != NULL) {
            if (root->data > key) {
                if (root->left != NULL && root->left->data == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->data == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
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
  
  node* root1=deleteNode(root,2);

  vector < int > inOrder;
  inOrderTrav(root1, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
 
  return 0;
}