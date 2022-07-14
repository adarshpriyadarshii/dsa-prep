#include <bits/stdc++.h>
using namespace std;

bool t[100][100];

vector<int> subset_sum(int wt[],int w,int n){
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
    vector<int> sum1;
    for(int i=0;i<=w/2;i++){
        if(t[n][i])sum1.push_back(i);
    }
    return sum1;
}

int min_diff(vector<int> v,int sum){
    int k=v.size();
    int mn=INT_MAX;
    for(int i=0;i<k;i++){
        mn=min(mn,abs(sum-2*v[i]));
    }
    return mn;
}

int main() {
    int wt[]={1,6,5,11};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=wt[i];
    }
    vector<int> ans=subset_sum(wt,sum,n);
    int sol=min_diff(ans,sum);
    cout<<sol;
    return 0;
}