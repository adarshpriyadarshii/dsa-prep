#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        int n=p.size();
        priority_queue<pair<int,pair<int,int>>> maxH;
        for(int i=0;i<n;i++){
            maxH.push({p[i][0]*p[i][0]+p[i][1]*p[i][1],{p[i][0],p[i][1]}});
            if(maxH.size()>k) maxH.pop();
        }
        vector<vector<int>> sol;
        while(maxH.size()>0){
            pair<int,int>p={maxH.top().second.first,maxH.top().second.second};
            sol.push_back({p.first,p.second});
            maxH.pop();
        }
        return sol;
    }

int main(){
    vector<vector<int>> arr;
    arr.push_back({1,3});
    arr.push_back({-2,2});
    arr.push_back({5,8});
    arr.push_back({0,1});
    //int n=sizeof(arr)/sizeof(arr[0]);
    int n=arr.size();
    int key=2;
    vector<vector<int>> ans=kClosest(arr,key);
    for(int i=0;i<n;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }

}