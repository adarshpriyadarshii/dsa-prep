#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n){
    int start=0;int end=n-2;
    while(start<=end){
        int mid=start+(end-start)/2;
         if((mid%2==0 && arr[mid]==arr[mid+1] )||(mid%2!=0 &&  arr[mid]==arr[mid-1]))start=mid+1;
        else end=mid-1;
    }
    return arr[start];
}
int main(){
    int arr[]={1,1,2,3,3,4,4,8,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=binarySearch(arr,n);
    cout<<ans;
    return 0;
}