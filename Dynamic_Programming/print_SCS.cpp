#include <bits/stdc++.h>
using namespace std;

string shortest_common_super_sequence(string x,string y,int n,int m){
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
    string ans;
    int i=m,j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;j--;
        }
        else {
            if(t[i-1][j]>t[i][j-1]){
                ans.push_back(x[i-1]);
                i--;
            }
            else {
                ans.push_back(y[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        ans.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(y[j-1]);
        j--;
    }
    return ans;
}

int main() {
    string x="abcdgh";
    string y="abcdfhr";
    int m=x.length();
    int n=y.length();
    string ans=shortest_common_super_sequence(x,y,n,m);
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}