#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void recursionMethod(node* root,int level,vector <int> &ans){
    if(root==NULL)return;
    if(ans.size()==level) ans.push_back(root->data);
    recursionMethod(root->right,level+1,ans);//for left view just put it below left.
    recursionMethod(root->left,level+1,ans);
}

vector<int> rightViewBT(node *root){
        vector<int> ans;
        recursionMethod(root,0,ans);
        return ans; 
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
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  vector < int > rightView;
  rightView = rightViewBT(root);
  cout<<"right VIEW : ";
  for(auto it:rightView){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}