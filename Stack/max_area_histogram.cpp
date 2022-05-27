#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={6,2,5,4,5,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> l,r,w,a;
    stack<pair<int,int>> s1,s2;
    //For Index of NSL:-
    for(int i=0;i<n;i++){
        if(s1.size()==0){
            l.push_back(-1);
        }
        else if(s1.size()>0 && s1.top().first<=arr[i]){
            l.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first>=arr[i]){
            while(s1.size()>0 && s1.top().first>=arr[i]){
                s1.pop();
            }
            if(s1.size()==0) l.push_back(-1);
            else{
                l.push_back(s1.top().second);
            }
        }
        s1.push({arr[i],i});
    }
    //For Index of NSR:-
    for(int i=n-1;i>=0;i--){
        if(s2.size()==0){
            r.push_back(n);
        }
        else if(s2.size()>0 && s2.top().first<=arr[i]){
            r.push_back(s2.top().second);
        }
        else if(s2.size()>0 && s2.top().first>=arr[i]){
            while(s2.size()>0 && s2.top().first>=arr[i]){
                s2.pop();
            }
            if(s2.size()==0) r.push_back(-1);
            else{
                r.push_back(s2.top().second);
            }
        }
        s2.push({arr[i],i});
    }
    reverse(r.begin(),r.end());
    //For Width:-
    for(int i=0;i<n;i++){
        w.push_back(r[i]-l[i]-1);
    }
    //For Area
    for(int i=0;i<n;i++){
        a.push_back(arr[i]*w[i]);
    }
    //Sorting to find Max Area
    sort(a.begin(),a.end());
    cout<<a[n-1];
    return 0;
}