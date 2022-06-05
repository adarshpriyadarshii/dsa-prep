#include <bits/stdc++.h>
using namespace std;

int Subarray_Sum(int n,int k,int a[]){
    int i=0,j=0,sum=0;
    int mx=INT_MIN;
    while(j<n){
        sum+=a[j];//Adding next element
        if((j-i+1)<k)j++;//Initial making window size of k
        else if((j-i+1)==k){
            mx=max(mx,sum);
            sum-=a[i];//Removing prev one element
            i++;j++;//Sliding Window
        }
    }
    return mx;
}

int main(){
    int n=7;
    int a[n]={2,5,3,7,9,8,6,};
    int k=3;
    int ans=Subarray_Sum(n,k,a);
    cout<<ans<<endl;
    return 0;
}