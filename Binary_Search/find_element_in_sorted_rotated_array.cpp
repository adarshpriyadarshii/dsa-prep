#include <bits/stdc++.h>
using namespace std;
int index(int arr[],int n){
    int start=0;int end=n-1;
    while(start<=end){
        if(arr[start]<=arr[end])return start;
        int mid=(start+end)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){return mid;}
        else if(arr[start]<=arr[mid]){ start=mid+1;}
        else if(arr[mid]<=arr[end]) {end=mid-1 ;}
    }
    return -1;
}
int binarySearch(int arr[],int start,int end,int x){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)return mid;
        else if(arr[mid]>x)end=mid-1;
        else start=mid+1;
    }
    return -1;
}
int main(){
    int arr[]={5,1,3};
    int x=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=index(arr,n);
    int first=binarySearch(arr,0,ans-1,x);
    int last=binarySearch(arr,ans,n-1,x);
    if(first == -1 && last !=-1)cout<<last;
   else if(last == -1 && first !=-1) cout<<first;
    else cout<<-1;

    return 0;
}