#include <bits/stdc++.h>
using namespace std;

int t[100][100];

int subset_sum_count(int coin[],int sum,int n){
   memset(t,0,sizeof(t));
   for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=(t[i][j-coin[i-1]])+(t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main() {
    int coin[]={1,2,3};
    int sum=5;
    int n=3;
    int ans=subset_sum_count(coin,sum,n);
    cout<<ans;
    return 0;
}