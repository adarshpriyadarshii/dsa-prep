#include <bits/stdc++.h>
using namespace std;

void Count(int a[],int k){
   unordered_map<int, int> m;
// Handling the 1st K elements
  for (int i = 0; i < k; i++)
    m[a[i]] = m[a[i]] + 1;
  cout << m.size() << " ";
  for (int i = k; i < 8; i++) {
// Removing the (i-k)th element
    if (m[a[i - k]] == 1){
      m.erase(a[i - k]);
      }
    else{
      m[a[i - k]] = m[a[i - k]] - 1;
      }
// Adding the next value in map
    m[a[i]] = m[a[i]] + 1;
    cout << m.size() << " ";
  }
  cout << endl;
}

int main(){
    int a[]={1,2,2,1,3,1,1,3};
    int key=4;
    Count(a,key);
}