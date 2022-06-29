#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ppi;

vector<int> k_Top_Element(int arr[],int n,int k){
    //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
    ppi minH;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it:m){
        minH.push({it.second,it.first});
        if(minH.size()>k) minH.pop();
    }
    vector<int> ans;
    while(minH.size()>0){
        ans.push_back(minH.top().second);
        minH.pop();
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