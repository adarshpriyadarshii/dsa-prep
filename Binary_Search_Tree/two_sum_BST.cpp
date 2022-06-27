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

class BSTIterator {
    stack<node *> myStack;
    bool reverse = true; 
public:
    BSTIterator(node *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        node *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }

private:
    void pushAll(node *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(node* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
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