#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int val;
  Node * left, * right;
};

vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value, here we are checking the direction actually.
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;//changing the direction
    result.push_back(row);
  }
  return result;
}
Node * newNode(int data) {
  Node * node = new Node;
  node -> val = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
int main() {
  int i, j;
  Node * root = newNode(1);
 root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);
  vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for (i = 0; i < ans.size(); i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}