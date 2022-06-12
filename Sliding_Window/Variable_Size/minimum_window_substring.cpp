#include<bits/stdc++.h>
using namespace std;
int Minimum_Substring(string s,string s1){
    unordered_map<char,int> mp;
    for(int i=0 ;i<s1.length();i++) {
        mp[s1[i]]++;
    }
    int ans=INT_MAX;
    int i=0,j=0;
    int count=mp.size();
    while(j<s.length()){
       if(mp.find(s[j])!=mp.end()){
           mp[s[j]]--;
           if(mp[s[j]]==0)count--;
        }
       if(count>0)j++;
       else if(count==0){
           ans=min(ans,j-i+1);
           while(count==0){
               if(mp.find(s[i])==mp.end()){
                   i++;
                   ans=min(ans,j-i+1);
                }
               else{
                   mp[s[i]]++;
                   if(mp[s[i]]>0){
                       i++;
                       count++;
                    }
                   else{
                       i++;
                       ans=min(ans,j-i+1);
                    }
               }
           }
           j++;
       }
    }
    return ans;
}
int main(){
    string s="totmtaptaptp";
    string s1="tta";
    int ans=Minimum_Substring(s,s1);
    cout<<ans<<endl;
    return 0;
}
