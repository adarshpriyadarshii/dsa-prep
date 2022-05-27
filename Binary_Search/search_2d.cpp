#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[4][4],int n,int m,int x){
    int i=0;int j=m-1;
    while(i>=0&&j>=0&&i<n&&j<m){
        if(arr[i][j]==x){
            return true;
        }
        else if(arr[i][j]>x)j--;
        else if(arr[i][j]<x) i++;
    }
    return false;
}
int main(){
    int a[4][4]= {{10, 20, 30, 40},{15, 25, 35, 45},{27, 29, 37, 48},{32, 33, 39, 50}};
    int x=29;
    int n=4;
    int m=4;
    bool ans=binarySearch(a,n,m,x);
    cout<<ans;
    return 0;
}