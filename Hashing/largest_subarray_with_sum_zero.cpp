#include <bits/stdc++.h>
using namespace std;

void largest_subarray_sum(int a[],int sum){
    int n=11;
    int currsum=0;
    int start=0;
    int end=-1;
    int len=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum-sum==0){
            start=0;end=i;
            len=max(len,end-start);
        }
        if(m.find(currsum-sum)!=m.end()){
            int k=m[currsum-sum];
            start=k+1;
            end=i;
            len=max(len,end-start);
        }
    m.insert(make_pair(currsum,i));
    }
    if(end==-1){
        cout<<"Not Found"<<endl;
    }else{
        cout<<len+1<<endl;
    }
}

int main(){
    int arr[]={1,0,1,0,0,1,0,1,0,1,1};
    int sum=0;
    for(int i=0;i<11;i++){
        if(arr[i]==0){
            arr[i]=-1;
        }
    }
    largest_subarray_sum(arr,sum);
}