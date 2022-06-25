#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector<int> preInPostTrav(node * root) {
    stack<pair<node*,int>> s;
    s.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL)return;
    while(!s.empty()){
        auto it=s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL){
                s.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL){
                s.push({it.first->right,1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
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

  vector < int > preInPost;
  preInPost=preInPostTrav(root);

  cout << "The preInPost Traversal is : ";
  for (int i = 0; i < preInPost.size(); i++) {
    cout << preInPost[i] << " ";
  }
  return 0;
}