#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> m;

bool Solve(string a,string b){
    if(a.compare(b)==0)return true;
    if(a.length()<=1) return false;

    string key=a+" "+b;
    if(m.find(key)!=m.end()){
        return m[key];
    }

    int n=a.length();
    bool f=false;
    for(int i=1;i<=n-1;i++){
        if((Solve(a.substr(0,i),b.substr(n-i,i)) && Solve(a.substr(i,n-i),b.substr(0,n-i))) 
        || (Solve(a.substr(0,i),b.substr(0,i)) && Solve(a.substr(i,n-i),b.substr(i,n-i)))) {
            f=true; 
            break;
        }
    }
    return m[key]=f;
}

int main(){
    string a="great";
    string b="rgeat";
    bool ans;
    if(a.length()!=b.length())ans=false;
    else if(a.empty() && b.empty())ans=true;
    else{
        ans=Solve(a,b);
    }
    cout<<(ans?"YES":"NO");
    return 0;
}