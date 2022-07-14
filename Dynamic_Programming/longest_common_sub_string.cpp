#include <bits/stdc++.h>
using namespace std;

int longest_common_subString(string x,string y,int n,int m){
    int t[m+1][n+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=0;
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            ans=max(ans,t[i][j]);
        }
    }
    return ans;
}

int main() {
    string x="abcdgh";
    string y="abcdfhr";
    int m=x.length();
    int n=y.length();
    int ans=longest_common_subString(x,y,n,m);
    cout<<ans;
    return 0;
}