#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={4,5};
    int x=2;
    int n=sizeof(a)/sizeof(a[0]);
    int ans=0;
    int start=0;int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==x)ans=a[mid];
        else if(a[mid]>x)end=mid-1;
        else start=mid+1;
    }
    if(ans==0)ans=min(abs(a[start]-x),abs(a[end]-x));
    cout<<ans;
    return 0;
}