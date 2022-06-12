#include <bits/stdc++.h>
using namespace std;

vector<int> Max_Elements(int a[],int n,int k){
    int i=0,j=0;
    deque<int> l;//list<int> l;
    vector<int> ans;
    while (j < n){
        while(l.size()>0 && l.back()<a[j]){
            l.pop_back();
        }
        l.push_back(a[j]);
        if (j-i+1 < k){
            j++;
        }
        else if (j-i+1 == k){
            ans.push_back(l.front());
            if(l.front()==a[i]){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    int n=8;
    int a[n]={1,3,-1,-3,5,3,6,8};
    int k=3;
    vector<int> ans=Max_Elements(a,n,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}