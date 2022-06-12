#include <bits/stdc++.h>
using namespace std;

int Largest_SubArray(int a[],int n,int k){
    int i=0,j=0,sum=0;
    int mx=INT_MIN;
    while (j < n){
       sum=sum+a[j];
       if(sum<k)j++;
       else if(sum==k){
           mx=max(mx,j-i+1);
           j++;
       }
       else if(sum>k){
           while(sum>k){
               sum=sum-a[i];
               i++;
               if(sum==k){
                   mx=max(mx,j-i+1);
               }
           }
          j++;
       }
      // j++;
    }
    return mx;
}

int main(){
    int n=4;
    int a[n]={5,1,2,3};
    int k=5;
    int ans=Largest_SubArray(a,n,k);
    cout<<ans;
    return 0;
}