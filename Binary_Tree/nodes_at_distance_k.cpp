#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void markParents(node* root, unordered_map<node*, node*> &parent_track, node* target) {
        queue<node*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            node* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

vector<int> distanceK(node* root, node* target, int k) {
        unordered_map<node*, node*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<node*, bool> visited; 
        queue<node*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                node* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            node* current = queue.front(); queue.pop();
            result.push_back(current->data);
        }
        return result;
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
 
  struct node* target=root->left->left;
  vector<int> sol;
  sol=distanceK(root,target,2);
  cout<<"The nodes are : ";
  for(auto it:sol){
    cout<<it<<" ";
  }
  return 0;
}