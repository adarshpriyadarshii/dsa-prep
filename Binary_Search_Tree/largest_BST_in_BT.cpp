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
class Nodedataue {
public:
    int maxNode, minNode, maxSize;
    
    Nodedataue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    Nodedataue largestBSTSubtreeHelper(node* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return Nodedataue(INT_MAX, INT_MIN, 0);
        }
        
        // Get dataues from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->data && root->data < right.minNode) {
            // It is a BST.
            return Nodedataue(min(root->data, left.minNode), max(root->data, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be dataid BST
        return Nodedataue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(node* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};
int main() {

  struct node * root = newNode(4);
  root->left=newNode(2);
  root->left->left=newNode(1);
  root->left->right=newNode(3);
  root->right=newNode(7);
  
  return 0;
}