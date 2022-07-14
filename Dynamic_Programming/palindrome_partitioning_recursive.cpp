#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}

int solve(string s,int i,int j){
    if(i>=j)return 0;
    if(isPalindrome(s,i,j))return 0;
    int res=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        res=min(res,temp);
    }
    return res;
}

int main() {
    string s="nintbnin";
    int n=s.length();
    int ans=solve(s,0,n-1);
    cout<<ans;
    return 0;
}