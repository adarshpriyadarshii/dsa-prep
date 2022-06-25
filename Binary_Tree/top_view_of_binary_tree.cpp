#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

 vector<int> topViewBT(node *root){
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; //checking if the node is already present or not.
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
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

  vector < int > topView;
  topView = topViewBT(root);
  cout<<"TOP VIEW : ";
  for(auto it:topView){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}