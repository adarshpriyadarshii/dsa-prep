#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int x){
    int start=0;int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)res= arr[mid];
        else if(arr[mid]<x){
            res=arr[mid];
            start=mid+1;
        }
        else end=mid-1;
    }
    return res;
}
int main(){
    int a[]={1,2,3,4,8,10,10,13,19};
    int x=5;
    int n=sizeof(a)/sizeof(a[0]);
    int ans=binarySearch(a,n,x);
    cout<<ans;
    return 0;
}