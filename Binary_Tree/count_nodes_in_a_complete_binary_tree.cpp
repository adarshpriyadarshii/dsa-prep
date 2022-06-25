#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int findHeightLeft(node* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
int findHeightRight(node* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }


int countNodes(node* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
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
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);
 
 int ans=countNodes(root);
  cout<<ans;
  return 0;
}