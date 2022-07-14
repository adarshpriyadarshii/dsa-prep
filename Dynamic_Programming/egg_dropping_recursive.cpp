#include <bits/stdc++.h>
using namespace std;

int Solve(int e,int f){
    if(f==0 || f==1) return f;
    if(e==0 || e==1) return f;
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(Solve(e-1,k-1),Solve(e,f-k));
        mn=min(mn,temp);
    }
    return mn;
}

int main() {
    int e=3;
    int f=5;
    int ans=Solve(e,f);
    cout<<ans;
    return 0;
}