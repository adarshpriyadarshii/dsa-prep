#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[],int n){
    priority_queue<int,vector<int>,greater<int>> minH;
    int cost=0;
    for(int i=0;i<n;i++){
        minH.push(arr[i]);
    }
    while(minH.size()>=2){
        int f=minH.top();
        minH.pop();
        int s=minH.top();
        minH.pop();
        cost=cost+f+s;
        minH.push(f+s);
    }
    return cost;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=minCost(arr,n);
    cout<<ans;
}