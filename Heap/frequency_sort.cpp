#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ppi;

vector<int> k_Top_Element(int arr[],int n,int k){
    priority_queue<pair<int,int>> maxH;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it:m){
        maxH.push({it.second,it.first});
    }
    vector<int> ans;
    while(maxH.size()>0){
        int f=maxH.top().first;
        int k=maxH.top().second;
        for(int i=0;i<f;i++){
            ans.push_back(k);
        }
        maxH.pop();
    }
    return ans;
}

int main(){
    int arr[]={1,1,1,3,2,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=2;
    vector<int> ans=k_Top_Element(arr,n,key);
    for(auto it:ans){
        cout<<it<<" ";
    }

}