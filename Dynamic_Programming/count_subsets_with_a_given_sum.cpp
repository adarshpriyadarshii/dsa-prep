#include <bits/stdc++.h>
using namespace std;

int t[100][100];

int subset_sum_count(int wt[],int w,int n){
   memset(t,0,sizeof(t));
   for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=(t[i-1][j-wt[i-1]])+(t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
}

int main() {
    int wt[]={2,3,5,8,10};
    int w=10;
    int n=5;
    int ans=subset_sum_count(wt,w,n);
    cout<<ans;
    return 0;
}