#include <bits/stdc++.h>
using namespace std;

int Longest_SubString(string s,int n,int k){
    unordered_map<char,int> m;
    int i=0,j=0;
    int mx=INT_MIN;
    while (j < n){
       m[s[j]]++;
       if(m.size()<k)j++;
       else if(m.size()==k){
           mx=max(mx,j-i+1);
           j++;
       }
       else if(m.size()>k){
           while(m.size()>k){
               m[s[i]]--;
               if(m[s[i]]==0){
                   m.erase(s[i]);
               }
               i++;
               if(m.size()==k){
                   mx=max(mx,j-i+1);
               }
           }
          j++;
       }
      // j++;
    }
    return mx;
}

int main(){
    string s="aabacbebebe";
    int n=s.length();
    int k=3;
    int ans=Longest_SubString(s,n,k);
    cout<<ans;
    return 0;
}