#include <bits/stdc++.h>
using namespace std;

int Subarray_Sum(string p,string s){
    unordered_map<char, int> mp;
    int ans = 0;
    for (auto &x : p){
        mp[x]++;
    }

    int count = mp.size();
    int k = p.size();
    int i=0, j=0;

    while (j < s.size()){
        if (mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if (mp[s[j]] == 0){
                count--;
            }
        }
        if (j-i+1 < k){
            j++;
        }
        else if (j-i+1 == k){
            if (count == 0){
                ans++;
            }
            if (mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if (mp[s[i]] == 1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    string s="forxxorfxdofr";
    string ptr="for";
    int ans=Subarray_Sum(ptr,s);
    cout<<ans<<endl;
    return 0;
}