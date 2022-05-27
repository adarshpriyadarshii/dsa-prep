#include <bits/stdc++.h>
using namespace std;
bool isValid(int arr[],int p,int x,int mx){
    int st=1;
    int sum=0;
    for(int i=0;i<p;i++){
        sum+=arr[i];
        if(sum>mx){
            st++;
            sum+=arr[i];
        }
        if(st>x)return false;
    }
    return true;
}
int binarySearch(int arr[],int n,int m,int p,int x){
    int start=n;
    int end=m;
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,p,x,mid)==true){
            res=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return res;
}
int main(){
    int a[]= {10,20,30,40};//pages in each book
    int x=2;//no. of students
    int p=4;//size of array
    int n=40;//max of array
    int m=100;//sum of all elemnets in array
    int ans=binarySearch(a,n,m,p,x);
    cout<<ans;
    return 0;
}