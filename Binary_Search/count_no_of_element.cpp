#include <bits/stdc++.h>
using namespace std;
int first(int arr[],int n,int x){
    int start=0;int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            res=mid;
            end=mid-1;;
        }
        else if(arr[mid]>x)end=mid-1;
        else start=mid+1;
    }
    return res;
}
int last(int arr[],int n,int x){
    int start=0;int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            res=mid;
            start=mid+1;
        }
        else if(arr[mid]>x)end=mid-1;
        else start=mid+1;
    }
    return res;
}
int main(){
    int a[7]={1,2,2,2,3,4,5};
    int x=2;
    int n=7;
    int f= first(a,n,x);
    int l=last(a,n,x);
    cout<<l-f+1;
    return 0;
}