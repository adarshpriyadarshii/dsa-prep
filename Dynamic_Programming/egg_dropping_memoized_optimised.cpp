#include <bits/stdc++.h>
using namespace std;

int t[51][51];

int Solve(int e,int f){
    if(f==0 || f==1) return f;
    if(e==0 || e==1) return f;

    if(t[e][f]!=-1) return t[e][f];

    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int low,high;

        if(t[e-1][k-1]!=-1){
            low=t[e-1][k-1];
        }
        else {
            low=Solve(e-1,k-1);
            t[e-1][k-1]=low;
        }

        if(t[e][f-k]!=-1){
            high=t[e][f-k];
        }
        else {
            high=Solve(e,f-k);
            t[e][f-k]=high;
        }

        int temp=1+max(low,high);
        mn=min(mn,temp);
    }
    return t[e][f]=mn;
}

int main() {
    int e=3;
    int f=5;
    memset(t,-1,sizeof(t));
    int ans=Solve(e,f);
    cout<<ans;
    return 0;
}