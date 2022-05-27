#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n){
    int start=0;int end=n-1;
    int res=-1;
    while(start<=end){
        if(arr[start]<=arr[end])return start;
        int mid=(start+end)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){res= mid;}
        else if(arr[start]<=arr[mid]){ start=mid+1;}
        else if(arr[mid]<=arr[end]) {end=mid-1 ;}
    }
    return res;
}
int main(){
    int arr[]={11,12,15,18,2,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=binarySearch(arr,n);
    cout<<ans;
    return 0;
}