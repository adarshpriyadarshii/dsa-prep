#include <bits/stdc++.h>
using namespace std;

int Longest_SubString(string s,int n){
    unordered_map<char,int> m;
    int i=0,j=0;
    int mx=INT_MIN;
    while (j < n){
       m[s[j]]++;
       //if(m.size()>k)j++; This case will never happen.
       if(m.size()==(j-i+1)){
           mx=max(mx,(j-i+1));
           j++;
       }
       else if(m.size()<(j-i+1)){
           while(m.size()<(j-i+1)){
               m[s[i]]--;
               if(m[s[i]]==0){
                   m.erase(s[i]);
               }
               i++;
               if(m.size()==j-i+1){
                   mx=max(mx,(j-i+1));
               }
           }
          j++;
       }
      // j++;
    }
    return mx;
}

int main(){
    string s="pwwkew";
    int n=s.length();
    int ans=Longest_SubString(s,n);
    cout<<ans;
    return 0;
}