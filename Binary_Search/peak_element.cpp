#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n){
    int start=0;int end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return  mid;
            else if(arr[mid+1]>arr[mid])start=mid+1;
            else end=mid-1 ;
        }
        else if(mid==0){
            return (arr[0]>arr[1]?0:1);
        }
        else if(mid==n-1){
            return (arr[n-1]>arr[n-2]?(n-1):(n-2));
        }
    }
    return -1;
}
int main(){
    int arr[]={2,1,2,3,4,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=binarySearch(arr,n);
    cout<<ans;
    return 0;
}