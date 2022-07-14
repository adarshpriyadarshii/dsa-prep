#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int solve(int arr[],int i,int j){
    if(i>=j)return 0;
    if(t[i][j]!=-1)return t[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int cost=arr[i-1]*arr[k]*arr[j];
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+cost;
        mn=min(mn,temp);
        t[i][j]=mn;
    }
    return t[i][j];
}

int main() {
    int arr[]={40,20,30,10,30};
    memset(t,-1,sizeof(t));
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=solve(arr,1,n-1);
    cout<<ans;
    return 0;
}