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
// Encodes a tree to a single string.
    string serialize(node* root) {
        if(!root) return "";
        
        string s ="";
        queue<node*> q;
        q.push(root);
        while(!q.empty()) {
           node* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->data)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    node* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        node *root = newNode(stoi(str));
        queue<node*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            node *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                struct node* leftNode = newNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                struct node* rightNode = newNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }

void printLevelOrder(node *root){
    if(root==NULL)return;
    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
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
 
 string sol=serialize(root);
 node* sol1=deserialize(sol);
 cout<<sol<<endl;
 printLevelOrder(sol1);
  return 0;
}