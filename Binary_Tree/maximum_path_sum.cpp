#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};



int findMaxPathSum(node * root, int & maxi) {
  if (root == NULL) return 0;

  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
  int val = root -> data;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
  return max(leftMaxPath, rightMaxPath) + val;

}

int maxPathSum(node * root) {
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;
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

  int ans=maxPathSum(root);
  cout<<ans<<endl;
  
  return 0;
}