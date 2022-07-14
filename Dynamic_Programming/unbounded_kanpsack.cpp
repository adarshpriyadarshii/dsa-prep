#include <bits/stdc++.h>
using namespace std;

int t[100][100];

int unbounded_knapsack(int wt[],int val[],int w,int n){
    memset(t,-1,sizeof(t));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
}

int main() {
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w=10;
    int n=4;
    int ans=unbounded_knapsack(wt,val,w,n);
    cout<<ans;
    return 0;
}