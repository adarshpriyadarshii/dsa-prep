#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int x){
    int start=0;int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)return mid;
        if(mid-1>=start && arr[mid-1]==x)return mid-1;
        if(mid+1<=end && arr[mid+1]==x)return mid+1;
        else if(arr[mid]>x)end=mid-2;
        else start=mid+2;
    }
    return -1;
}
int main(){
    int arr[]={5,10,30,20,50};
    int x=20;
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=binarySearch(arr,n,x);
    cout<<ans;
    return 0;
}