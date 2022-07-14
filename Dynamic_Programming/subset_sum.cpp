#include <bits/stdc++.h>
using namespace std;

bool t[100][100];

bool knapsack(int wt[],int w,int n){
   memset(t,0,sizeof(t));
   for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j]=(t[i-1][j-wt[i-1]])||(t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];
}

int main() {
    int wt[]={2,3,7,8,10};
    int w=11;
    int n=4;
    bool ans=knapsack(wt,w,n);
    cout<<(ans?"YES":"NO");
    return 0;
}