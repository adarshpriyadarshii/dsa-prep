#include <bits/stdc++.h>
using namespace std;
bool isValid(int a[],int n,int c,int mx){
    int cow=1;
    int last=a[0];
    for(int i=0;i<n;i++){
        int diff=a[i]-last;
        if(diff>=mx){
            cow++;
            last=a[i];
        }
        if(cow>=c)return true;
    }
     return false;
}
int binarySearch(int a[],int n,int c){
    int start=0;
    int end=a[n-1]-a[0];
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(a,n,c,mid)){
            res=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    return res;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int ans=binarySearch(a,n,c);
        cout<<ans;
    }
    return 0;
}