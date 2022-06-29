#include <bits/stdc++.h>
using namespace std;

vector<int> k_Closest(int arr[],int n,int k,int x){
    priority_queue<pair<int,int>> maxH;
    for(int i=0;i<n;i++){
        maxH.push({abs(arr[i]-x),arr[i]});
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    vector<int> sol;
    while(maxH.size()>0){
        sol.push_back(maxH.top().second);
        maxH.pop();
    }
    return sol;
}

int main(){
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=3;
    int x=7;
    vector<int> ans=k_Closest(arr,n,key,x);
    for(auto it:ans){
        cout<<it<<" ";
    }
}