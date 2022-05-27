#include <bits/stdc++.h>
using namespace std;

int main(){
    char arr[]={'a','b','g','h'};
    char x='e';
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=0;int end=n-1;
    char res=' ';
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)start=mid+1;
        else if(arr[mid]>x){
            res=arr[mid];
             end=mid-1;
        }
        else start=mid+1;
    }
    cout<<res;
    return 0;
}