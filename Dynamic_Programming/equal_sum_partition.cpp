#include <bits/stdc++.h>
using namespace std;

bool t[100][100];

bool subset_sum(int wt[],int w,int n){
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

bool equal_sum_partition(int wt[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=wt[i];
    }
    if(sum%2) return false;
    else {
        return subset_sum(wt,sum/2,n);
    }
}

int main() {
    int wt[]={1,5,11,5};
    int n=4;
    bool ans=equal_sum_partition(wt,n);
    cout<<(ans?"YES":"NO");
    return 0;
}