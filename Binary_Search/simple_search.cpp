#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int x){
    int start=0;int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)return mid;
        else if(arr[mid]>x)end=mid-1;
        else start=mid+1;
    }
    return -1;
}
int main(){
    int a[7]={1,2,2,2,3,4,5};
    int x=2;
    int n=7;
    int ans=binarySearch(a,n,x);
    cout<<ans;
    return 0;
}