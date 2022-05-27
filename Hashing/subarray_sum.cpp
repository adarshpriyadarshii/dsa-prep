#include <bits/stdc++.h>
using namespace std;

void subarray_sum(int a[],int sum){
    int n=4;
    int currsum=0;
    int start=0;
    int end=-1;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum-sum==0){
            start=0;end=i;
            break;
        }
        if(m.find(currsum-sum)!=m.end()){
            int k=m[currsum-sum];
            start=k+1;
            end=i;
            break;
        }
    m.insert(make_pair(currsum,i));
    }
    if(end==-1){
        cout<<"Not Found"<<endl;
    }else{
        cout<<start<<" "<<end<<endl;
    }
}

int main(){
    int arr[]={10,-5,2,10};
    int sum=15;
    subarray_sum(arr,sum);
}