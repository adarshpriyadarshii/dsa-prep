#include <bits/stdc++.h>
using namespace std;

vector<int> klargest(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> minH;
    vector<int> ans;
    for(int i=0;i<n;i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            ans.push_back(minH.top());
            minH.pop();
        }
    }
    while(minH.size()>0){
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}

int main(){
    int arr[]={6, 5, 3, 2, 8, 10, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=3;
    vector<int> ans=klargest(arr,n,key);
    for(auto it:ans){
        cout<<it<<" ";
    }

}