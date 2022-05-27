#include <bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;
void getMin(){
    if(ss.size()==0) cout<< -1<<endl;
    cout<< ss.top()<<endl;
}
void Push(int a){
    s.push(a);
    if(ss.size()==0 || ss.top()>=a) ss.push(a);
    return;
}
void Pop(){
    if(s.size()==0)cout<<-1<<endl;
    int ans = s.top();
    s.pop();
    if(ss.top()==ans)ss.pop();
    cout<<ans<<endl;
}

int main(){
    Push(18);
    Push(19);
    Push(29);
    getMin();
    Pop();
    Push(15);
    Push(16);
    getMin();
    Pop();
    return 0;
}