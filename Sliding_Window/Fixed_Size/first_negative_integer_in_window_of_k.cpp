#include <bits/stdc++.h>
using namespace std;

void First_Negative(int n,int k,int a[]){
    int i=0,j=0;
    queue<int> q;
    vector<int> ans;
    while(j<n){
       if(a[j]<0)q.push(a[j]);
       if(j-i+1<k)j++;
       else if(j-i+1==k){
           if(q.empty())ans.push_back(0);
           else{
               ans.push_back(q.front());
               if(q.front()==a[i])q.pop();
           }
           i++;
           j++;
       }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=8;
    int a[n]={12,-1,-7,8,-15,30,16,28};
    int k=3;
    First_Negative(n,k,a);
    return 0;
}