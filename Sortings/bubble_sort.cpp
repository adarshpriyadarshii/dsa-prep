#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=1;
    while(cnt<n){
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
               int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
              // swap(a[i],a[i+1]); // we can use swap func as well.
            }
        }
        cnt++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}